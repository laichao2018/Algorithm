// Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

class Tree {
private:
	enum { T_SIZE = 100 };
	struct Node
	{
	public:
		int item;
		Node *leftchild;
		Node *rightchild;
		Node(const int & i = 0) :item(i), leftchild(0), rightchild(0) {  };
	};
	int items;
	const int Tsize;
	Tree(const Tree & q) : Tsize(0) {};
	Node *root;

	void _TraversePreorder(Node *root)
	{
		cout << root->item << " ";
		if (root->leftchild != NULL) _TraversePreorder(root->leftchild);
		if (root->rightchild != NULL) _TraversePreorder(root->rightchild);
	}

	void _TraverseInorder(Node *root)
	{
		if (root->leftchild != 0) _TraverseInorder(root->leftchild);
		cout << root->item << " ";
		if (root->rightchild != 0) _TraverseInorder(root->rightchild);
	}

	void _TraversePostorder(Node *root)
	{
		if (root->leftchild != 0) _TraversePostorder(root->leftchild);
		if (root->rightchild != 0) _TraversePostorder(root->rightchild);
		cout << root->item << " ";
	}

	void _TraverseDepthFirst(Node *root)
	{
		queue<Node*> *children = new queue<Node*>();
		children->push(root);
		while (!children->empty())
		{
			Node* temp = children->front();
			children->pop();
			cout << temp->item << " ";
			if (temp->leftchild != 0) children->push(temp->leftchild);
			if (temp->rightchild != 0) children->push(temp->rightchild);
		}
	}
public:
	Tree(int ts = T_SIZE);
	void creat()
	{
		root->item = 15;
		Node *node1 = new Node(11);
		Node *node2 = new Node(10);
		Node *node3 = new Node(7);
		Node *node4 = new Node(5);
		Node *node5 = new Node(9);
		Node *node6 = new Node(2);
		Node *node7 = new Node(6);
		Node *node8 = new Node(4);
		Node *node9 = new Node(3);
		Node *node10 = new Node(1);
		Node *node11 = new Node(8);
		root->leftchild = node1;
		root->rightchild = node2;
		node1->leftchild = node3;
		node1->rightchild = node4;
		node3->leftchild = node7;
		node3->rightchild = node8;
		node4->leftchild = node9;
		node4->rightchild = node10;
		node2->leftchild = node5;
		node2->rightchild = node6;
		node5->leftchild = node11;
	}
	void TraversePreorder()
	{
		_TraversePreorder(root);
	}
	void _TraverseInorder()
	{
		_TraverseInorder(root);
	}
	void TraversePostorder()
	{
		_TraversePostorder(root);
	}
	void TraverseDepthFirst()
	{
		_TraverseDepthFirst(root);
	}
};


int main()
{
	Tree *T = new Tree();
	T->creat();
	//T->TraversePreorder();	//前
	//T->TraverseInorder();	//中
	//T->TraversePostorder();	//后
	T->TraverseDepthFirst();
	cout << endl;
	return 0;
}

Tree::Tree(int ts):Tsize(ts)
{
	root = new Node(15);
	items = 0;
}
