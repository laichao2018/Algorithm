// 5.3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Lnode {
	int data;
	Lnode *next;
	Lnode() {
		data = 0;
		next = NULL;
	}
};
/*没啥卵用

struct Smark {
	Smark *top;
	int length;
}s;
void initSmark(Smark &s) {
	s.top = NULL;
	s.length = 0;
}
*/
struct Stack {
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
    return 0;
}

