// 归并排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_SIZE 10
void MergeSort(int a[], int tem[], int start, int end)
{
	if (start >= end)    return;
	int mid_point = (start + end) / 2;

	MergeSort(a, tem, start, mid_point);
	MergeSort(a, tem, mid_point + 1, end);

	int left_index = start;
	int right_index = mid_point + 1;
	int tem_index = left_index;

	while ((left_index <= mid_point) && (right_index <= end))
	{
		if (a[left_index] < a[right_index])
		{
			tem[tem_index++] = a[left_index++];
		}
		else
		{
			tem[tem_index++] = a[right_index++];
		}
	}

	for (int i = left_index; i <= mid_point; i++)
	{
		tem[tem_index++] = a[i];
	}
	for (int i = right_index; i <= end; i++)
	{
		tem[tem_index++] = a[i];
	}
	for (int i = start; i <= end; i++)
	{
		a[i] = tem[i];
	}
}
int main()
{
	srand(time(0));
	int a[MAX_SIZE], tem[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		a[i] = rand() % MAX_SIZE + 1;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	MergeSort(a, tem, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}

