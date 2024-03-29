// 查找零.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

#define MaxError 0.001

float FindZero(float f(float x), float dfdx(float x), float initial_guess, float maxError) {
	float x = initial_guess;
	for (int i = 1; i <= 100; i++) {
		float y = f(x);
		if (abs(y) < maxError) break;
		x = x - y / dfdx(x);
	}
	return x;
}
float f(float x) {
	float y = pow(x, 2) - x;
	return y;
}
float dfdx(float x) {
	float y = 2 * x - 1;
	return y;
}
int main()
{
	int a;
	int ans;
	while (cin >> a) {
		ans = FindZero(f, dfdx, a, MaxError);
		cout << ans << " ";
	}
    return 0;
}

