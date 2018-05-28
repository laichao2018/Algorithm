// 计数排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_SIZE 10

void CountintSort(int a[], int size)
{
	int count[MAX_SIZE + 1] = { 0 };
	for (int i = 0; i < MAX_SIZE; i++)
	{
		count[a[i]] = count[a[i]] + 1;
	}
	int index = 0;

	for (int i = 0; i <= MAX_SIZE; i++)
	{
		for (int j = 1; j <= count[i]; j++)
		{
			a[index] = i;
			index += 1;
		}
	}
}
int main()
{
	srand(time(0));
	int a[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		a[i] = rand() % MAX_SIZE + 1;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	CountintSort(a, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}

