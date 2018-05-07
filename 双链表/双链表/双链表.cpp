// 双链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct  DLList
{
	int data;
	DLList *next;
	DLList *pro;
	DLList() {
		data = 0;
		next = NULL;
		pro = NULL;
	}
};
void CreatCell(DLList *top,int size) {			//创建链表
	while (top) {
		for (int i = 1; i <= size; i++) {
			//DLList *tem = new DLList();
			//tem = top;
			top->next = new DLList();
			//top->pro = new DLList();
			top->next->pro = top;
			top = top->next;
			top->data = i;
			if (i == size) {
				top->next = new DLList();
				top->next->pro = top;
				top = top->next;
			}
		}
		top = top->next;
	}
}
int ListLen(DLList *top) {				//链表长度
	int i = 0;
	top = top->next;
	while (top) {
		i++;
		top = top->next;
	}
	return i;
}
void PrintList(DLList *top,int size) {			//打印链表
	//top = top->next;
	//while (top->next != NULL) {
	for (int i = 1; i <= size+1 && top != NULL; i++) {
			cout << top->data << " ";
			top = top->next;
		}
	//}
	cout << '\n';
}
void InsertList(DLList *head, int target) {		//插入节点
	DLList *new_cell = new DLList();
	while (head != NULL) {
		if (head->data == target) {
			
			new_cell->next = head->next;
			head->next = new_cell;
			new_cell->next->pro = new_cell;
			new_cell->pro = head;
			
			new_cell->data = 7;
		}
		head = head->next;
	}
}
void DeleteCell(DLList *head, int target) {
	while (head != NULL) {
		if (head->data == target) {
			head->next->pro = head->pro;
			head->pro->next = head->next;
		}
		head = head->next;
	}
}
void insertCell_orderly(DLList *head, DLList *new_cell) {			//对有序链表进行插入
	while (head->next != NULL && head->next->data < new_cell->data) {
		head = head->next;
	}
	
	new_cell->next = head->next;
	head->next = new_cell;
	new_cell->next->pro = new_cell;
	new_cell->pro = head;
}
int main()
{
	DLList *head = new DLList();
	int len;
	CreatCell(head, 6);
	len = ListLen(head);
	cout << len << " " << '\n';
	PrintList(head, len);
	InsertList(head, 6);
	len = ListLen(head);
	PrintList(head, len+1);
	cout << len << endl;
	DLList *new_cell = new DLList();
	new_cell->data = 5;
	insertCell_orderly(head, new_cell);
	len = ListLen(head);
	PrintList(head, len);
	cout << len << '\n';
	DeleteCell(head, 3);
	len = ListLen(head);
	PrintList(head, len);
    return 0;
}

