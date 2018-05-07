// 尾部添加单元格.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct List {
	int value;
	List *next;
	int  *rear;
	List() {
		value = 0;
		next = NULL;
		rear = NULL;
	}
}L;

void creat(List *tem, int size) {
	List *top = tem;
	for (int i = 1; i <= size;i++) {
		tem->next = new List();
		tem = tem->next;
		tem->value = i;
		if (tem->next == NULL) {
			top->rear = (int *)tem;
		}
	}
}
void printList(List *tem) {
	while (tem != NULL)
	{
		cout << tem->value << " ";
		tem = tem->next;
	}
	cout << endl;
}
void rearinsertValue(List *tem){
	//List *rear = tem->rear;
	tem = (List *)tem->rear;
	tem->next = new List();
	tem = tem->next;
	tem->value = 7;
	tem->rear = (int *)tem;
}
List *rearList(List *tem) {
	List *rear = new List();
	while (tem != NULL) {
		if (tem->next == NULL)
		{
			rear = tem;
			break;
		}
		tem = tem->next;
	}
	return rear;
}
int main()
{
	List *head = new List();
	List *rear = new List();
	creat(head,6);
	printList(head);
	//cout << (int *)head->rear;
	//rear = rearList(head);
	rearinsertValue(head);
	printList(head);
    return 0;
}

