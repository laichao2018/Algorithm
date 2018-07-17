// 排序树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//#include "Tree.h"

using namespace std;

struct Node
{
	int data;
	Node *lchild, *rchild;
	Node(const int& data = 0) :data(0), lchild(0), rchild(0) {};
};
Node* build(Node* root, int val)
{
	if (root == NULL)
	{
		Node* root = new Node();
		root->data = val;
		return root;
	}
	if (root->data < val) root->lchild = build(root->lchild, val);
	else root->rchild = build(root->rchild, val);
	return root;
}

Node* FindNode(Node* root, int target)
{
	if (target == root->data) return root;

	if (target < root->data)
	{
		if (root->rchild == NULL) return NULL;
		return FindNode(root->lchild, target);
	}
	else
	{
		if (root->rchild == NULL) return NULL;
		return FindNode(root->rchild, target);
	}
}
bool TraversePreorder(Node * root)
{
	cout << root->data << " ";
	if (root->lchild != 0) TraversePreorder(root->lchild);
	if (root->rchild != 0) TraversePreorder(root->rchild);
	return true;
}

int main()
{
	int a[] = { 5,1,1,2,3,4,5,6,7,8,9 };
	Node *root = NULL;
	for (int i = 0; i <= 10; i++)
		root = build(root, a[i]);
	TraversePreorder(root);
	cout << endl;
	Node* ans;
	ans = FindNode(root, 5);
	cout << ans->data << endl;
	//Node *root = new Node(10);
    return 0;
}

