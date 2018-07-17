#pragma once
#ifndef TREE_B_
#define TREE_B_
#include <queue>;
template<class T>
class BinaryTreeNode
{
	friend void Visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<Y> *);
	friend void main(void)j;
public:
	BinaryTreeNode() { LeftChild = RightChild = 0; }
	BinaryTreeNode(const T&e)
	{
		data = e;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T&e, BinaryTreeNode*l, BinaryTreeNode*r)
	{
		data = e;
		LeftChild = l;
		RightChild = r;
	}
private:
	T data;
	BinaryTreeNode<T> *LeftChild, *RightChild;
};
template<class T>
void Visit(BinaryTreeNode<T> *t)
{
	cout << t->data << " ";
}
template<class T>
void InOrder(BinaryTreeNode<T>* t)
{
	if (t)
	{
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}
template<class T>
void PreOrder(BinaryTreeNode<T> *t)
{
	if (t)
	{
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
template<class T>
void PostOrder(BinaryTreeNode<T> *t)
{
	if (t)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}
template<class T>
void LevelOrder(BinaryTreeNode<T> *t)
{
	std::queue<BinaryTreeNode<T>*> Q;
	while (t)
	{
		Visit(t);
		if (t->LeftChild)Q.push(t->LeftChild);
		if (t->RightChild)Q.push(t->RightChild);
		Q.front();
		Q.pop();
	}
}
template<class T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root;
};

#endif // 
