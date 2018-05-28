// 桶排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_SIZE 10

struct array
{
	int value[MAX_SIZE];
	int mark[MAX_SIZE];
	array()
	{
		value[MAX_SIZE] = { 0 };
		mark[MAX_SIZE] = 0;
	}
}tem;
int main()
{
	srand(time(0));
	int a[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		a[i] = rand() % MAX_SIZE;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		tem.value[a[i]] = a[i];
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (tem.value[a[i]] == a[i])
		{
			tem.mark[a[i]]++;
		}
	}
	int index = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		while (tem.mark[i]--)
		{
			a[index++] = tem.value[i];
		}
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

