// LinkList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

#define  MAX_SIZE 10

typedef struct List
{
	int data;
	List *next;
}LinkList;
//存数据
LinkList *Inset(LinkList *head)
{
	int i;
	head = new LinkList();
	LinkList *top = head;
	for (i = 0;i < MAX_SIZE;i++ )
	{
		top->next = new LinkList();
		top->data = rand() % 10 + 1;
		top = top->next;
	}
	return head;
}
//查找结点
LinkList *FindNode(LinkList *head,int target)
{
	while (head)
	{
		if (head->data == target)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}
//头插入结点
LinkList *InsertNode(LinkList *head)
{
	LinkList *new_Node = new LinkList();
	new_Node->next = head;
	new_Node->data = 11;
	return new_Node;
}
//尾插入结点
void Insert_rear(LinkList *head)
{
	LinkList *new_Node = new LinkList();
	new_Node->data = 11;
	while (head->next)
	{
		head = head->next;
	}
	head->next = new_Node;
	new_Node->next = NULL;
}
//固定点插入
void Insert_Node(LinkList *head,int target)
{
	LinkList *new_Node = new LinkList();
	new_Node->data = 11;
	new_Node->next = NULL;
	while (head)
	{
		if (head->data == target)
		{
			new_Node->next = head->next;
			head->next = new_Node;
			
		}
		head = head->next;
	}
	if (new_Node->next == NULL)
	{
		cout << "NO";
	}
}
//复制链表
LinkList *CopyList(LinkList *head)
{
	LinkList *new_temp = new LinkList();
	LinkList *temp = new_temp;
	while (head)
	{
		temp->next = new LinkList();
		temp->data = head->data;
		temp = temp->next;
		head = head->next;
	}
	return new_temp;
}

//链表插入排序
LinkList *Insert_Sort(LinkList *head)
{
	LinkList *after_node = new LinkList();
	after_node->next = NULL;
	
	while (head)
	{
		LinkList *next_cell = head;
		
		head = head->next;
		
		LinkList *temp = after_node;
		while (temp->next != NULL && temp->next->data < next_cell->data)
		{
			temp = temp->next;
		}

		next_cell->next = temp->next;
		temp->next = next_cell;
	}
	return after_node;
}
//链表选择排序
LinkList *CelectionSort(LinkList *input) 
{
	LinkList *after_sort = new LinkList();
	after_sort->next = NULL;

	while (input->next != NULL)
	{
		LinkList *best_after_me = input;
		int best_value = best_after_me->next->data;

		LinkList *after_me = input;
		while (after_me->next)
		{
			if (after_me->next->data > best_value)
			{
				best_after_me = after_me;
				best_value = after_me->next->data;
			}
			after_me = after_me->next;
		}
		LinkList *best_cell = best_after_me->next;
		best_after_me->next = best_cell->next;

		best_cell->next = after_sort->next;
		after_sort->next = best_cell;
	}
	return after_sort;
}
//遍历链表
void Print_l(LinkList *head)
{
	while (head)
	{
		cout << head->data << "\t";
		head = head->next;
	}
	cout << '\n';
}
int main()
{
	srand(time(0));
	LinkList *top = new LinkList();
	LinkList *new_top = new LinkList();
	top = Inset(top);
	//LinkList *temp = FindNode(top,3);
	//top = InsertNode(top);
	//Insert_rear(top);
	//Insert_Node(top, 4);
	new_top = CopyList(top);
	LinkList *sort_node = new LinkList();
	sort_node = CelectionSort(top);
	Print_l(new_top);
	Print_l(sort_node);
	return 0;
}

