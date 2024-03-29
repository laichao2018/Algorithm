// 二分搜索.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX_SIZE 100

void swap(int & a,int & b)
{
	int tem = a;
	a = b;
	b = tem;
}
/**
void Sort(int a[], int size)
{
	bool sort_ok = true;
	while (sort_ok)
	{
		sort_ok = false;
		for (int i = 0; i < MAX_SIZE; i++) 
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				sort_ok = true;
			}
		}
	}
}*/

void Sort(int a[], const int _start, const int _end)
{
	int start = _start;
	int end = _end;
	if (start >= end) return;
	int pivotkey = a[start];
	while (start < end)
	{
		while (start < end && a[end] >= pivotkey)
			end--;
		a[start] = a[end];
		while (start < end && a[start] < pivotkey)
			start++;
		a[end] = a[start];
	}
	a[start] = pivotkey;
	Sort(a, _start, start - 1);
	Sort(a, start + 1, _end);
}
//*****二分搜索
int BinarySearch(int (&a)[MAX_SIZE],int target)
{
	int min = 0;
	int max = sizeof a / sizeof a[0];
	std::cout << max << " " << std::endl;
	//int max = MAX_SIZE - 1;
	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (target < a[mid]) max = mid - 1;
		else if (target > a[mid]) min = mid + 1;
		else return mid;
	}
	return -1;
}

/****插值搜索*/

int InterpolationSearch(int (&a)[MAX_SIZE],int target)
{
	int min = 0;
	int max = sizeof a / sizeof a[0];
	while (min <= max)
	{
		int mid = min + (max - min) * (target - a[0]) / (a[max] - a[min]);
		if (a[mid] == target) return mid;
		else if (a[mid] < target)
		{
			min = mid + 1;
		}
		else if (a[mid] > target) max = mid - 1;
	}
	return -1;
}
int main()
{
	//using namespace std;
	srand(time(NULL));
	int a[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		a[i] = rand() % MAX_SIZE + 1;
	//std::cout << std::endl;
	a[0] = 23;
	Sort(a, 0, MAX_SIZE - 1);
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		std::cout << a[i] << " ";
	}
	
	int ans1 = InterpolationSearch(a, 23);
	int ans2 = BinarySearch(a, 23);
	std::cout << ans1 << std::endl;
	std::cout << ans2 << std::endl;
	return 0;
}

