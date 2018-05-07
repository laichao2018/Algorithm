// 数组栈.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void Push(int a[],int len, int *next_index, int value) {
	//if (*next_index == len) ;
	a[*next_index] = value;
	*next_index = *next_index + 1;
}
int Pop(int a[],int *next_index) {
	if (next_index == 0) return 0;
	*next_index = *next_index - 1;

	return a[*next_index];

}
void PrintL(int a[],int p) {
	while (p--)
	{
		printf_s("%d ", a[p]);
	}
}
int main()
{
	int a[100] = {0};
	int p = 0;
	int *next_index = &p;
	int len = sizeof a / sizeof(a[0]);
	Push(a, len, next_index, 6);
	Push(a, len, next_index, 5);
	Push(a, len, next_index, 4);
	Pop(a, next_index);
	PrintL(a, p);
	printf("\n");
	printf_s("%d", *next_index );
    return 0;
}

