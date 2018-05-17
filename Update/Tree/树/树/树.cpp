// 树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define  MAX_SIZE 20

typedef int ElemType;
//双亲表示法
typedef struct Snode	//结点结构
{
	ElemType data;
	int parent;
}Pnode;
typedef struct			//树结构
{
	Pnode tnode[MAX_SIZE];
	int n;				//结点个数
}Ptree;
void MakeHeap(int value[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int index = i;
		while (index != 0)
		{
			int parent = (index - 1) / 2;
			if (value[index] <= value[parent])
			{
				break;
			}
			int temp = value[index];
			value[index] = value[parent];
			value[parent] = temp;

			index = parent;
		}
	}
}

int RemoveTopItem(int value[], int count)
{
	int result = value[0];

	value[0] = value[MAX_SIZE - 1];
	int index = 0;
	while (1)
	{
		int child1 = 2 * index + 1;
		int child2 = 2 * index + 2;
		
		if (child1 >= count) child1 = index;
		if (child2 >= count) child2 = index;

		if (value[index] >= value[child1] && value[index] >= value[child2])
		{
			break;
		}

		int swap_child;
		if (value[child1] > value[child2])
			swap_child = child1;
		else
			swap_child = child2;

		int temp = value[index];
		value[index] = value[swap_child];
		value[swap_child] = temp;

		index = swap_child;
	}
	return result;
}
void HeapSort(int value[])
{
	MakeHeap(value);

	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		int temp = value[0];
		value[0] = value[i];
		value[i] = temp;

		RemoveTopItem(value, i);
		//MakeHeap(value);
	}
}
/*
//这是啥我也知道
void InitTree(int value[],Ptree &tree)
{
	int i, j;
	char ch;
	for (i =0;i < MAX_SIZE;i++)
	{
		tree.tnode[i].data = value[i];
		tree.tnode[i].parent = (i - 1) / 2;
	}
	tree.tnode[0].parent = -1;
}
*/
void InitArray(int value[], int size)
{
	for (int i = 0; i < size; i++)
	{
		value[i] = rand() % MAX_SIZE + 1;
	}
}
void TraverseArray(int value[], int size)
{
	for (int i =0;i < size;i++)
	{
		cout << value[i] << "  ";
	}
	cout << "\n";
}
int main()
{
	Ptree tree;
	srand(time(0));
	int value[MAX_SIZE];
	InitArray(value, MAX_SIZE);//初始化数组
	//TraverseArray(value, MAX_SIZE);	//遍历数组
	MakeHeap(value);	//转换数组为堆
	TraverseArray(value, MAX_SIZE);
	RemoveTopItem(value, MAX_SIZE);
	//HeapSort(value);
	TraverseArray(value, MAX_SIZE);
    return 0;
}

