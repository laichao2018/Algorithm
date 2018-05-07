// 数值积分-矩形规则.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100000

float UseRectangleRule(float function(float x), float xmin, float xmax, int num_intervals);
float function(float x);
int main()
{
	float a, b;
	cin >> a >> b;
	float f;
	f = UseRectangleRule(function, a, b, MAX);
	cout << f << endl;
    return 0;
}
float UseRectangleRule(float function(float x), float xmin, float xmax, int num_intervals) {
	float dx = (xmax - xmin) / num_intervals;
	float total_area = 0;
	float x = xmin;
	for(int i = 0; i < num_intervals; i++) {
		total_area = total_area + dx * function(x);
		x = x + dx;
	}
	return total_area;
}
float function(float x) {
	float y;
	//y = 1 + x + sin(2 * x);
	y = x;
	return y;
}