// 复制链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

typedef struct LNode {
	int data;
	LNode *next;
	LNode() {
		data = 7;
		next = NULL;
	}
};
int createList(LNode *L, int size) {					//插入数据
	LNode *tem;
	tem = L;
	for (int i = 1; i <= size; i++) {
		//tem->data = 1 + rand() % size;
		tem->next = new LNode();
		tem = tem->next;
		tem->data = i;
	}
	return 1;
}
int ListLen(LNode *L) {			//链表长度
	int i = 0;
	while (L) {
		i++;
		L = L->next;
	}
	return i;
}
LNode *FindCell(LNode *L, int target) {				//查找单元格
	while (L) {
		if (L->data == target) return L;
		L = L->next;
	}
	return NULL;
}
LNode *FindCellOptimize(LNode *L, int target) {
	//检查第一个单元格是否为空
	if (L == NULL) return NULL;
	while (L->next != NULL) {
		if (L->next->data == target) return L;
		L = L->next;
	}
	return NULL;
}
void AddAtBeginning(LNode *L, LNode *newL) {			//在开头添加单元格
	newL->next = L->next;
	L->next = newL;
	newL->data = 0;
}
void AddAtEnding(LNode *L, LNode *newL) {			//在结尾处添加单元格
	while (L->next != NULL)
		L = L->next;
	L->next = newL;
	newL->next = NULL;
}
void DeleteCell(LNode *L, int target) {				//删除节点
	LNode *tem = new LNode();
	while (L->next != NULL) {
		if (L->next->data == target) {
			tem = L->next;
			L->next = L->next->next;

		}
		L = L->next;
	}
	delete(tem);
}
void PrintList(LNode *L, int size) {					//打印链表
	while (L) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
LNode *CopyList(LNode *old_cell) {
	LNode *new_cell = new LNode();
	LNode *last_adden = new_cell;
	old_cell = old_cell->next;
	while (old_cell) {
		last_adden->next = new LNode();
		last_adden = last_adden->next;

		last_adden->data = old_cell->data;
		old_cell = old_cell->next;
	}
	last_adden->next = NULL;
	return new_cell;
}
int main()
{
	//srand(time(0));
	LNode *head, *tem;
	head = new LNode();
	tem = new LNode();
	LNode *temp = new LNode();
	createList(head, 6);		//调用创建链表
	//AddAtBeginning(head, tem);
	//AddAtEnding(head, temp);
	int len = ListLen(head);
	//PrintList(head, len);			//打印
	//LNode *ans = FindCell(head, 5);
	//cout << ans->data << '\n';
	//LNode *ans = FindCellOptimize(head, 3);
	//cout << ans->data << '\n';
	//DeleteCell(head, 4);		//删除
	PrintList(head, len);			//打印
	//cout << len << " " << '\n';
	LNode *new_cell = CopyList(head);
	PrintList(new_cell, len);
	return 0;
}