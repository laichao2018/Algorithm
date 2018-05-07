// 数值积分-自适应积分.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10000
#define MIN 0.00001

double SliceArea(float function(float x), float x1, float x2, float max_slice_error);
double UseTrapezoidRule(float function(float x), float xmin, float xmax, int num_intervals,float max_slice_error) {
	float dx = (xmax - xmin) / num_intervals;
	double total_area = 0;
	float x = xmin;
	for (int i = 1; i < num_intervals; i++) {
		total_area += SliceArea(function,x,x+dx,max_slice_error);
		x += dx;
	}
	return total_area;
}
double SliceArea(float function(float x), float x1, float x2, float max_slice_error) {
	float y1 = function(x1);
	float y2 = function(x2);
	float xm = (x1 + x2) / 2;
	float ym = function(xm);
	double area12 = (x2 - x1) * (y1 + y2) / 2.0;
	double area1m = (xm - x1) * (ym + y1) / 2.0;
	double area2m = (x2 - xm) * (y2 + ym) / 2.0;
	double aream12m = area1m + area2m;
	double error = (aream12m - area12) / area12;
	if (abs(error) < max_slice_error) return aream12m;
	return SliceArea(function, x1, xm, max_slice_error) + SliceArea(function, x2, xm, max_slice_error);
}
float function(float x) {
	float y;
	y = x;
	return y;
}
int main()
{
	float a, b;
	float ans;
	while (cin >> a >> b) {
		ans = UseTrapezoidRule(function, a, b, MAX, MIN);
		cout << ans << " ";
	}
	return 0;
}

