// 6.Sort.cpp: 定义控制台应用程序的入口点。
//
//从小到大

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX_SIZE 20

void Insertsort(int *a, int size);		//插入排序
void SelectionSort(int a[], int size);		//选择排序
void BubbleSort(int a[], int size);		//冒泡排序
void InitA(int a[], int size);		//初始化
void PrintA(int a[], int size);		//打印数组
int main()
{
	srand(time(0));
	int a[MAX_SIZE];
	InitA(a, MAX_SIZE);
	//Insertsort(a, MAX_SIZE);
	//SelectionSort(a, MAX_SIZE);
	BubbleSort(a, MAX_SIZE);
	PrintA(a, MAX_SIZE);
    return 0;
}

void Insertsort(int *a, int size) {
	for (int i = 1; i < MAX_SIZE; i++) {
		int temp = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > temp) {
				a[j + 1] = a[j];
				a[j] = temp;
			}
			else break;
		}
	}
}
void SelectionSort(int a[], int size){
	for (int i = 0; i < MAX_SIZE; i++) {
		int temp = a[i];
		for (int j = i; j < MAX_SIZE; j++) {
			if (a[j] < temp) {
				temp = a[j];
			}
		}
		a[i] = temp;
	}
}
void BubbleSort(int a[], int size){
	bool not_sort = true;
	int i = 0;
	while (not_sort) {
		not_sort = false;
		for (i = 0; i < MAX_SIZE - 1; i++) {
			if (a[i] > a[i + 1]) {
				int tem = a[i];
				a[i] = a[i + 1];
				a[i + 1] = a[i];
				
				not_sort = true;
			}
		}
	}
}
void InitA(int a[], int size) {
	for (int i = 0; i < MAX_SIZE; i++)
		a[i] = rand() % MAX_SIZE + 1;
}
void PrintA(int a[], int size) {
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}