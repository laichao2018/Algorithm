// 5.2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Lnode{
	int data;
	Lnode *next;
	Lnode() {
		data = 0;
		next = NULL;
	}
};

struct Smark{
	int *top;
	int length;
}s;
struct Stack{
	Lnode *sentinel = new Lnode;
	int Push(int Value) {
		Lnode *temp = new Lnode;
		temp->data = Value;
		temp->next = sentinel->next;
		sentinel->next = temp;
		return temp->data;
	}
	int pop() {
		if (sentinel->next == NULL)	return 0;
		int Value = sentinel->next->data;
		sentinel->next = sentinel->next->next;
		return Value;
	}
};
int main()
{
	Stack s1, s2;
	s.length = 0;
	s.top = NULL;
	int temp;
	for (int i = 1; i <= 5; i++) {
		temp = s1.Push(i);
	}
	for (int i = 1; i <= 5; i++) {
		s2.Push(s1.pop());
	}
	for (int i = 1; i <= 5; i++) {
		printf_s("%d\t", s2.pop());
	}
	printf("\n");
    return 0;
}

