// int_rand_List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct L {
	int data;
	L *next;
	L() {
		data = 0;
		next = NULL;
	}
};

void creat(L *tem, int size) {
	L *temp = new L();
	for (int i = 1; i <= size; i++) {
		tem->next = new L();
		tem = tem->next;
		tem->data = 1 + rand() % 6;
	}
}
void printList(L *tem) {
	while (tem != NULL)
	{
		printf_s("%d ", tem->data);
		tem = tem->next;
	}
	cout << endl;
}
L *max_List(L *tem) {
	L *temp = new L();
	int value = tem->data;
	while (tem != NULL) {
		if (tem->data > value) {
			value = tem->data;
			temp = tem;
		}
		tem = tem->next;
	}
	return temp;
}
int main()
{
	srand(time(0));
	L *head = new L();
	creat(head,6);
	printList(head);
	L *max_L = new L();
	max_L = max_List(head);
	cout << max_L->data << " " << (int *)max_L << endl;
    return 0;
}

