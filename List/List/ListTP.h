#pragma once
#ifndef LIST_H_
#define LIST_H_

template<class Item>
class ListTP
{
private:
	enum { L_SIZE = 10 };
	struct Node
	{
	public:
		Item item;
		Node *next;
		Node *prev;
		Node(const Item & i = 0) : item(i), next(0) ,prev(0){};
	};
	Node *front;
	Node *rear;

	int items;
	const int lsize;
	ListTP(const ListTP & q) : lsize(0) {};
	ListTP & operator= (const ListTP & q) { return *this; }
public:
	ListTP(int qs = L_SIZE);
	~ListTP();
	bool isempty() const
	{
		return items == 0;
	}
	bool isfull() const
	{
		return items == lsize;
	}
	int listcount() const
	{
		return items;
	}
	bool push_back(const Item & item);
	bool push_front(const Item & item);
	bool pop_back(Item & item);
	bool pop_front(Item & item);
};
template<class Item>
inline ListTP<Item>::ListTP(int qs) :lsize(qs)
{
	front = rear = 0;
	items = 0;
}

template<class Item>
ListTP<Item>::~ListTP()
{
	Node * temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<class Item>
bool ListTP<Item>::push_back(const Item & item)
{
	if (isfull())
		return false;
	Node *add = new Node(item);
	items++;
	if (front == 0)
		front = add;
	else
	{
		rear->next = add;
		add->prev = rear;
	}
	rear = add;
	return true;
}
template<class Item>
bool ListTP<Item>::push_front(const Item & item)
{
	if (isfull())
		return false;
	Node *add = new Node(item);
	items++;
	if (front == 0)
		front = add;
	else
	{
		add->next = front;
		front->prev = add;
	}
	front = add;
	return true;
}
template<class Item>
bool ListTP<Item>::pop_back(Item & item)
{
	if (front == 0)
		return false;
	item = rear->item;
	items--;
	Node *temp = rear;
	rear = rear->prev;
	delete temp;
	if (items == 0)
		front = 0;
	return true;
}
template<class Item>
bool ListTP<Item>::pop_front(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node *temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}
#endif // !LIST_H_


