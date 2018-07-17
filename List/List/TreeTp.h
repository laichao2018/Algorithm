#pragma once
#ifndef TREE_H_
#define TREE_H_

template<typename Item>
class TreeTP
{
private:
	enum {T_SIZE = 10};
	struct Node
	{
	public:
		Item item;
		Node *leftchild;
		Node *rightchild;
		Node(const Item & i = 0) :item(i), leftchild(0), rightchild(0) {  };
	};
	Node *root;

	int items;
	const int tsize;
	TreeTP(const TreeTP & q) :qsize(0) {};
public:
	TreeTP(const int ts = T_SIZE);
	~TreeTP();
	bool isempty() const;
	bool isfull() const;
};

template<typename Item>
inline TreeTP<Item>::TreeTP(const int ts)
{
	root = 0;
	items = 0;
}

template<typename Item>
inline TreeTP<Item>::~TreeTP()
{
	Node *temp;
	if (root != 0)
	{
		temp = root;
		
	}
}

template<typename Item>
inline bool TreeTP<Item>::isempty() const
{
	return items == 0;
}

template<typename Item>
inline bool TreeTP<Item>::isfull() const
{
	return items == T_SIZE;
}

#endif // !TREE_H_

