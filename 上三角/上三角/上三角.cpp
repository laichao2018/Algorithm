// 上三角.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void creat(int *a[], int size) {
	int n = size + 1;
	for (int i = 0; i < size; i++) {
		a[i] = new int[n];
		for (int j = i; j < size; j++) {
			a[i][j] = 21;
		}
	}
}
void print(int *a[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int *a[9];
	creat(a, 9);
	print(a, 9);
    return 0;
}

