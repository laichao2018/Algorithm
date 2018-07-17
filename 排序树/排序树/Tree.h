#pragma once
#ifndef TREE_T_
#define TREE_T_

//ERROR
template<typename T>
class Tree
{
private:
	enum { T_SIZE = 10 };
	struct Node {
		T data;
		Node *lchild;
		Node *rchild;
		Node(const T& data = 0) : data(0), lchild(0), rchild(0) {};
	};
	Node *root;

	int items;
	const int tsize;
	Tree(const Tree & q) : tsize(0) {};
public:
	Tree(int ts = T_SIZE);
	~Tree();
	bool AddNode(const T value);
	bool _AddNode(Node *root, const T value);
	bool isfull();
	bool TraversePreorder() const;
	bool _TraversePreorder(Node *root) const;
};
template<typename T>
Tree<T>::Tree(int ts) : tsize(ts)
{
	root = 0;
	items = 0;
}
template <typename T>
Tree<T>::~Tree()
{
	cout << "Îö¹¹Íê³É" << endl;
}

template<typename T>
inline bool Tree<T>::AddNode(const T value)
{
	_AddNode(root, value);
	return true;
}

template<typename T>
inline bool Tree<T>::_AddNode(Node * root, const T value)
{
	if (isfull()) return false;
	Node *temp = new Node(value);
	items++;
	if (root == 0) 
	{
		root = temp;
	}
	else
	{
		if (temp->data < root->data)
		{
			if (root->lchild == 0) root->lchild = temp;
			else
			{
				_AddNode(root->lchild, value);
			}
		}
		else
		{
			if (root->rchild == 0) root->rchild = temp;
			else {
				_AddNode(root->rchild, value);
			}
		}
	}
	return true;
}

template<typename T>
inline bool Tree<T>::isfull()
{
	return items == tsize;
}

template<typename T>
bool Tree<T>::TraversePreorder() const
{
	_TraversePreorder(root);
	return true;
}

template<typename T>
bool Tree<T>::_TraversePreorder(Node * root) const
{
	cout << root->data << " ";
	if (root->lchild != 0) _TraversePreorder(root->lchild);
	if (root->rchild != 0) _TraversePreorder(root->rchild);
	return true;
}


#endif // !TREE_T_
