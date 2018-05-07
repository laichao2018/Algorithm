// 三角数组相加相乘.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int *a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = new int[i + 1];
		for (int j = 0; j <= i; j++) {
			a[i][j] = 1;
		}
	}
	int *b[10];
	for (int i = 0; i < 10; i++) {
		b[i] = new int[i + 1];
		for (int j = 0; j <= i; j++) {
			b[i][j] = 1;
		}
	}
	/*相加
	int *resault[10];
	for (int i = 0; i < 10; i++) {
	resault[i] = new int[i + 1];
	for (int j = 0; j <= i; j++) {
	resault[i][j] = a[i][j] + b[i][j];
	}
	}
	*/
	//相乘
	int *resault[10];
	for (int i = 0; i < 10; i++) {
		resault[i] = new int[i + 1];
		for (int j = 0; j <= i; j++) {
			resault[i][j] = 0;
			for (int k = j; k <= i; k++) {
				resault[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			cout << resault[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}

