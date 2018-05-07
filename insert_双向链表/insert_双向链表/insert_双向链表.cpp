// insert_双向链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct L {
	int data;
	L *prev;
	L *next;
	L() {
		prev = NULL;
		next = NULL;
		data = 0;
	}
};
int *creat(L *top, int size, int *rear) {
	L *tem = top;
	for (int i = 1; i <= size; i++) {
		top->next = new L();
		top = top->next;
		top->prev = tem;
		tem = top;
		top->data = i;
		//top->data = 1 + rand() % 6;
		if (i == size) {
			rear = (int*)top;
		}
	}
	return rear;
}

void printL(L *top) {
	while (top) {
		printf_s("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}
void insertCell(L *top,L *tem) {
	if (tem->next != NULL) {
		tem->next = top->next;
		top->next = tem;

		tem->next->prev = tem;
		tem->prev = top;
	}
	else {
		tem->next = top->next;
		top->next = tem;

		tem->prev = top;
	}
}
void inserHead(L *top) {
	/*L *tem = new L();
	tem->next = top->next;
	top->next->prev = tem;

	tem->prev = top;
	top->next = tem;
	*/
	L *tem = new L();
	tem->data = 1;
	insertCell(top,tem);
	//tem->data = 1;
}
int *insertRear(L *top, int *rear) {
	/*top = (L *)rear;
	top->next = new L();
	top = top->next;
	top->data = 7;
	top->prev = (L *)rear;
	rear = (int *)top;
	*/
	L *tem = new L();
	tem->data = 7;
	insertCell((L *)rear, tem);
	return rear;
}
bool sort_of_List(L *top) {
	L *tem = top;
	while (top) {
		while (tem) {
			if (tem->data < top->data) {
				return false;
			}
			tem = tem->next;
		}
		top = top->next;
		tem = top;
	}
	return true;
}
int main()
{
	srand(time(0));
	L *head = new L();
	int *rear = NULL;
	rear = creat(head, 6, rear);
	printL(head);
	//inserHead(head);
	//printL(head);
	//rear = insertRear(head, rear);
	//printL(head);
	bool ans = sort_of_List(head);
	cout << ans << '\n';
	return 0;
}