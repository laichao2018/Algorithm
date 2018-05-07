// 双向循环链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct T {
	int data;
	T *next;
	T *prev;
	T() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
};
void creat(T *tem,int size){
	T *top = tem;
	for (int i = 1; i <= size; i++) {
		tem->next = new T();
		tem = tem->next;
		tem->data = i;
		if (tem->next == NULL) {
			tem->next = top;
			top->prev = tem;
		}
	}
}
void printT(T *tem) {
	T *top = tem;
	tem = tem->next;
	while (tem != top) {
		printf_s("%d ", tem->data);
		tem = tem->next;
	}
	cout << endl;
}
int main()
{
	T *top;
	top = new T();
	creat(top, 6);
	printT(top);
    return 0;
}

