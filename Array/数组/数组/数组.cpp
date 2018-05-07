// 数组.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void init_array(int a[],int length) {
	for (int i = 0; i < length; i++)
		a[i] = i;
}
void insert(int a[], int len, int position) {
	for (int i = len - 1; i > position; i--) {
		a[i] = a[i - 1];
	}
	a[position] = 99;
}
void print_array(int a[],int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int a[20] = { 0 };
	int len = sizeof(a) / sizeof(a[0]);
	init_array(a, len);
	print_array(a, len);
	insert(a, len, 3);
	print_array(a, len);
    return 0;
}

