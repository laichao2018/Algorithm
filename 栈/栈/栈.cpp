// 栈.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct  L
{
	int data;
	L *next;
	L() {
		data = 0;
		next = NULL;
	}
};

void Push(L *sentinel, int value) {
	L *new_cell = new L();
	new_cell->data = value;
	
	new_cell->next = sentinel->next;
	sentinel->next = new_cell;
}
int Pop(L *sentinel) {
	if (sentinel->next == NULL) throw 0;
	int value = sentinel->next->data;
	
	sentinel->next = sentinel->next->next;
	return value;
}
void PrintL(L *sentinel) {
	while (sentinel != NULL) {
		printf_s("%d ", sentinel->data);
		sentinel = sentinel->next;
	}
	printf_s("\n");
}
int main()
{
	L *sentinel = new L();
	Push(sentinel, 10);
	Push(sentinel, 9);
	PrintL(sentinel);
	int del = Pop(sentinel);
	PrintL(sentinel);
	printf("%d ", del, "\n");
    return 0;
}

