// 单循环链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct  Cir_List
{
	int data;
	Cir_List *next;
	Cir_List() {
		data = 0;
		next = NULL;
	}
};

void creatList(Cir_List *tem,int size);
bool hasloopList(Cir_List *tem);
void printList(Cir_List *tem);

int main()
{
	Cir_List *top = new Cir_List();
	creatList(top, 6);
	//bool has_ans = hasloopList(top);
	//cout << has_ans << endl;
	printList(top);
    return 0;
}
void creatList(Cir_List *tem, int size) {
	Cir_List *top = tem;
	for (int i = 1; i <= size; i++) {
		tem->next = new Cir_List();
		tem = tem->next;
		tem->data = i;
		if (tem->next == NULL) {
			tem->next = top->next;
		}
	}
}

bool hasloopList(Cir_List *tem) {
	Cir_List *top = tem;
	while (top->next != NULL){
		Cir_List *top_1 = tem;
		while (top_1 != top) {
			if (top_1->next == top->next) {
				//top->next = NULL;
				return true;
			}
			top_1 = top_1->next;
		}
		top = top->next;
	}
	return false;
}
void printList(Cir_List *tem) {
	Cir_List *top = tem;
	if (hasloopList(top)) {
		tem = tem->next; 
		while (tem->next != top->next) {
			//cout << (int *)tem << " ";
			printf_s("%d ", tem->data);
			tem = tem->next;
		}
		printf("\n");
	}
	else {
		while (tem->next !=NULL)
		{
			printf_s("%d ", tem->data);
			tem = tem->next;
		}
		printf_s("\n");
	}
}