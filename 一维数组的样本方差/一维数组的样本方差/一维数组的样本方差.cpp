// 一维数组的样本方差.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	int b = 0;
	for (int i = 0; i < 10; i++) {
		b += a[i];
	}
	b = b / sizeof(a) / sizeof(a[0]);
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (a[i] - b)*(a[i] - b) / (sizeof(a) / sizeof(a[0]));
	}
	cout << ans;
    return 0;
}

