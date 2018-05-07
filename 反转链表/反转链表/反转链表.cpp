// 反转链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct  Cir_list {
	int data;
	Cir_list *next;
	Cir_list() {
		data = 0;
		next = NULL;
	}
};

void creatList(Cir_list *tem,int size);
void printList(Cir_list *tem);
Cir_list *ReverseList(Cir_list *tem);
bool hasloopList(Cir_list *tem);
void printList_1(Cir_list *tem, int size);
int main()
{
	Cir_list *top = new Cir_list();
	creatList(top,6);
	printList(top);
	Cir_list *ans = ReverseList(top);
	printList(top);
	//printList_1(ans,8);
	bool ans_loop = hasloopList(top);
	cout << ans_loop << endl;
    return 0;
}
void creatList(Cir_list *tem, int size) {
	Cir_list *top = tem;
	for (int i = 1; i <= size; i++) {
		tem->next = new Cir_list();
		tem = tem->next;
		tem->data = i;
		if (tem->next == NULL) {
			tem->next = top->next;
		}
	}
}

void printList(Cir_list *tem) {
	Cir_list *top = tem;
	tem = tem->next;
	do
	{
		printf_s("%d ", tem->data);
		//cout << tem->data << " ";
		tem = tem->next;
	}while(tem->next != top->next->next);
	cout << endl;
}
void printList_1(Cir_list *tem,int size) {
	for (int i = 1; i <= size; i++) {
		cout << tem->data << " ";
		tem = tem->next;
	}
	cout << endl;
}

Cir_list *ReverseList(Cir_list *tem) {
	Cir_list *prev = NULL;
	Cir_list *curr = tem;
	while (curr != NULL)
	{
		Cir_list *next = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = next;
	}
	return prev;
}
bool hasloopList(Cir_list *tem) {
	if (tem->next == NULL) return false;
	Cir_list *new_tem = ReverseList(tem);

	ReverseList(new_tem);

	if (new_tem == tem) return true;
	
	return false;
}