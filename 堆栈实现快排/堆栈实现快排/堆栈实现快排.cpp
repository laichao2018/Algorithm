#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define  MAX_SIZE 20
typedef int ElemType;
struct Node
{
	ElemType data[MAX_SIZE];
	int index;
	Node()
	{
		index = 0;
	}
};
struct Stack
{
	Node top;
	void InitStack()
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			top.data[i] = rand() % MAX_SIZE + 1;
			top.index = i;
		}
	}
	void Push(int value)

	{
		if (top.index == MAX_SIZE - 1) exit(OVERFLOW);
		top.data[top.index] = value;
		top.index++;
	}
	int Pop()
	{
		if (top.index == 0) return -1;
		return top.data[top.index--];
	}
	void TraverseStack()
	{
		int temp = top.index - 1;
		while (temp >= 0)
		{
			cout << top.data[temp--] << " ";
		}
		cout << endl;
		//cout << top.index;
	}
};
int main()
{
	srand(time(NULL));
	Stack s;
	//s.InitStack();
	s.Push(12);
	s.TraverseStack();
	return 0;
}
