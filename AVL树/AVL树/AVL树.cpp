// AVL树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

struct  Node
{
	int val;
	int count;
	Node* left;
	Node* right;
	Node() : val(0), count(0), left(0), right(0) {};
};

int Tree_height(Node* root)
{
	if (root == NULL) return -1;
	return root->count;
}
static Node* build(Node *root,int val)
{
	if (root == NULL) {
		root = new Node();
		root->val = val;
		return root;
	}
	if (val < root->val) root->left = build(root->left, val);
	else root->right = build(root->right, val);
	return root;
}
void Tra(Node* root)
{
	cout << root->val << " ";
	if (root->left != NULL) Tra(root->left);
	if (root->right != NULL) Tra(root->right);
}
Node* search(Node *root,int target)
{
	if (root->val == target) return root;
	if (target < root->val) {
		if (root->left == NULL) return NULL;
		search(root->left, target);
	}
	else {
		if (root->right == NULL) return NULL;
		search(root->right, target);
	}
}
int main()
{
	Node *root = NULL;
	int c[] = { 5 ,8,7,5,4,3,2 };
	for(auto i : c)
		root = build(root, i);
	Tra(root);
	return 0;
}

