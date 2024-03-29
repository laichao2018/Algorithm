// 矩阵.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T> const T& min(const T& a, const T& b, const T& c, const T& d) {
	const T& m = !(b < a) ? a : b;
	const T& n = !(c < d) ? d : c;
	return !(m < n) ? n : m;
	//return !(b<a) ? a : b;     // or: return !comp(b,a)?a:b; for version (2)
}



int main()
{
	/*左下方1，右上方0，对角线2
	int a[10][10] = {0};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < 10; i++) {
			a[i][i] = 2;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	/*
	//左上方1，对角线2，右下方0
	int a[5][5] = { 0 };
	for (int i = 0; i < 5; i++)
		a[4 - i][i] = 2;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int a[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = min(i, j,9 - i,9 - j);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}

