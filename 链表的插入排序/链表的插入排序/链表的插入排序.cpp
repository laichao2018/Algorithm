// 链表的插入排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct  List
{
	int data;
	List *next;
	List() {
		data = 0;
		next = NULL;
	}
}*head,*head_copy;

void creatList(List *top,int size) {			//创建链表
	for (int i = 1; i <= size; i++) {
		top->next = new List();
		top = top->next;
		top->data = i;
	}
}
void creatListRand(List *top, int size) {		//创建随机数值链表
	for (int i = 1; i <= size; i++) {
		top->next = new List();
		top = top->next;
		top->data = 1 + rand() % 10;;
	}
}

List *copyList(List *old_cell) {			//拷贝链表
	List *new_sentinel = new List();
	List *last_add = new_sentinel;
	old_cell = old_cell->next;
	while (old_cell) {
		last_add->next = new List();
		last_add = last_add->next;
		last_add->data = old_cell->data;
		old_cell = old_cell->next;
	}
	return new_sentinel;
}

void PrintList(List *top) {			//打印
	while (top) {
		printf_s("%d ", top->data);
		top = top->next;
	}
	printf_s("\n");
}

void insertCell(List *l1, List *l2) {		//插入节点
	l2->next = l1->next;
	l1->next = l2;
}

List *insertionsort(List *sentinel,List *old_cell) {		//将链表插入到一个已经排序的链表中
	//List *sentinel = new List();
	//sentinel->next = NULL;

	old_cell = old_cell->next;
	while (old_cell) {
		List *next_cell = old_cell;
		List *after_me = sentinel;
		old_cell = old_cell->next;
		
		while (after_me->next && after_me->next->data < next_cell->data) {
			after_me = after_me->next;
		}
		
		next_cell->next = after_me->next;
		after_me->next = next_cell;
	}
	return sentinel;
}
List *insertion_sort(List *old_cell) {			//插入排序
	List *sentinel = new List();
	sentinel->next = NULL;

	old_cell = old_cell->next;

	while (old_cell) {
		List *next_cell = old_cell;
		List *after_me = sentinel;
		old_cell = old_cell->next;
		while (after_me->next && after_me->next->data < next_cell->data)
			after_me = after_me->next;
		//next_cell->next = after_me->next;
		//after_me->next = next_cell;
		insertCell(after_me, next_cell);
	}
	return sentinel;
}

List *selectionsort(List *old_cell) {		//选择插入排序
	List *sentinel = new List();
	sentinel->next = NULL;
	
	
	while (old_cell->next)
	{	
		List *best_after_me = old_cell;
		int best_value = best_after_me->next->data;
		List *after_me = old_cell->next;
		while (after_me->next) {
			if (after_me->next->data > best_value) {
				best_after_me = after_me;
				best_value = after_me->next->data;
			}
			after_me = after_me->next;
		}
		//移除best_cell
		List *best_cell = best_after_me->next;
		best_after_me->next = best_cell->next;
		PrintList(old_cell);
		//将best_cell添加到新序列
		best_cell->next = sentinel->next;
		sentinel->next = best_cell;

	}
	return sentinel;
}

int main()
{
	srand(time(0));
	head = new List();

	//head_copy = new List();
	//creatList(head, 6);
	//PrintList(head);
	
	//head_copy = copyList(head);
	//PrintList(head_copy);
	
	//List *head_sort = new List();
	//head_sort = insertionsort(head_copy,head);
	//PrintList(head_sort);
	//随机链表插入排序
	//List *head_rand = new List();
	//creatListRand(head_rand,6);
	//PrintList(head_rand);
	//head_rand = insertion_sort(head_rand);
	//PrintList(head_rand);

	List *head_insert_rand = new List();
	creatListRand(head_insert_rand, 6);
	PrintList(head_insert_rand);
	head_insert_rand = selectionsort(head_insert_rand);
	PrintList(head_insert_rand);
    return 0;
}

