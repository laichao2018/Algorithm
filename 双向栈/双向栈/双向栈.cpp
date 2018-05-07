#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX_size 100
/*数组实现
struct  Shed
{
private:
	int tail = 0, front = MAX_size - 1;
public:
	//const int MAX_size = 100;
	int a[MAX_size];

	int Push_tail(int value) {
		if (tail > front) return 0;
		return a[tail++] = value;
	}
	int Push_front(int value) {
		if (tail > front) return 0;
		{
			return a[front--] = value;
		}
	}
	int Pop_tail() {
		if (tail > front) return 0;
		return a[--tail];
	}
	int Pop_front() {
		if (tail > front) return 0;
		return a[++front];
	}
	void PrintShed() {
		int i = tail;
		while (i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	void Printfront() {
		int j = front;
		while (j++ != MAX_size) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
}a;

void ReserveArray(int value[]) {
	for (int i = 0; i < 3; i++)
		a.Push_tail(value[i]);
	for (int i = 0; i < 3; i++) {
		value[i] = a.Pop_tail();
	}
}
*/
//链表实现
struct Stack{
	int data;
	Stack *next;
	Stack() {
		data = 0;
		next = NULL;
	}
	int Push(int value) {
		Stack *temp = new Stack;
		temp->data = value;

		temp->next = sentinel->next;
		sentinel->next = temp;

		return temp->data;
	}
	int Pop() {
		if (sentinel->next == NULL) return 0;

		int temp = sentinel->next->data;
		sentinel->next = sentinel->next->next;

		return temp;
	}
}*sentinel,holding1,holding2,output,train;

void reset() {
	int i = 0;
	while (sentinel->next != NULL) {
		if (train.Pop() == 1)	holding1.Push(train.Pop());
		if (train.Pop() == 2)	holding2.Push(train.Pop());
		if (train.Pop() == 3) output.Push(train.Pop());
		cout << i++ << "第一个";
	}
	while (sentinel->next != NULL){
		train.Push(output.Pop());
		printf("%d\d", i++, "dierge");
	}
	while (sentinel->next != NULL){
		train.Push(holding2.Pop());
		printf("%d\d", i++, "disange");
	}
	while (sentinel->next != NULL){
		train.Push(holding1.Pop());
		printf("%d\d", i++, "disige");
	}
}

int main() {
	srand(time(NULL));
	sentinel = new Stack;
	int tem;
	for (int i = 0; i < 5; i++) {
		tem = rand() % 3 + 1;
		train.Push(tem);
	}
	reset();
	for (int i = 0; i < 5; i++) {
		printf_s("%d\t", train.Pop());
	}
	printf_s("\n");
	return 0;
}