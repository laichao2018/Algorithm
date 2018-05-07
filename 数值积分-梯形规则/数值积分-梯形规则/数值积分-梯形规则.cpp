// 数值积分-梯形规则.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10000

float UseTrapezoidRule(float function(float x), float xmin, float xmax, int num_intervals) {
	float dx = (xmax - xmin) / num_intervals;
	float total_area = 0;
	float x = xmin;
	for (int i = 1; i < num_intervals; i++) {
		total_area += dx * (function(x) + function(x + dx)) / 2;
		x += dx;
	}
	return total_area;
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
		ans = UseTrapezoidRule(function, a, b, MAX);
		cout << ans << " ";
	}
    return 0;
}

