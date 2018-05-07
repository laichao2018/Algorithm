// 散列表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct  Cir_List{
	int data;
	Cir_List *next;
	Cir_List() {
		data = 0;
		next = NULL;
	}
};

bool hasloopretracing(Cir_List *tem);
void creatList(Cir_List *tem, int size);
void PrintList(Cir_List *tem);

void creatList(Cir_List *tem,int size) {
	Cir_List *top = tem;
	for (int i = 1; i <= size; i++) {
		tem->next = new Cir_List();
		tem = tem->next;
		tem->data = i;
		/*if (tem->next == NULL)
			tem->next = top;*/
	}

	return;
}
void PrintList(Cir_List *tem) {
	Cir_List *top = tem;
	if (hasloopretracing(tem)) {
		while (tem->next != top)
		{
			printf_s("%d ", tem->data);
			tem = tem->next;
		}
		cout << endl;
	}else{
		while (tem->next != NULL)
		{
			printf_s("%d ", tem->data);
			tem = tem->next;
		}
		cout << endl;
	}
}

//如果链表包含一个循环返回true
//如果链表包含一个循环，破坏它
bool hasloopretracing(Cir_List *tem) {
	Cir_List *top = tem;
	while (top->next != NULL) {
		Cir_List *top_1 = tem;
		while (top_1 != top) {
			if (top_1 == top->next) {
				top->next = NULL;
				return true;
			}
			top_1 = top_1->next;
		}
		top = top->next;
	}
	return false;
}
int main()
{
	Cir_List *top = new Cir_List();
	creatList(top, 6);
	PrintList(top);
	bool loop_ans = hasloopretracing(top);
	cout << loop_ans << endl;
    return 0;
}

