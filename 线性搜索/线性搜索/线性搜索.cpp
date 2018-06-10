// 线性搜索.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_SIZE 10

void Swap(int &a,int &b)
{
	int tem = a;
	a = b;
	b = a;
}
void ArraySort(int a[], int size)
{
	bool not_ok = true;
	while (not_ok)
	{
		not_ok = false;
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				not_ok = true;
			}
		}
	}
}
int LinearSearch(int a[],int target)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (a[i] == target)  return i;
		if (a[i] > target)  return -2;
	}
	return -1;
}
int main()
{
	srand(time(0));
	int a[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		a[i] = rand() % MAX_SIZE + 1;
	}
	ArraySort(a, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int target = 5;
	int ans = LinearSearch(a, target);
	cout << target << " at " << ans+1 << endl;
    return 0;
}

