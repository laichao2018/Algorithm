// List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "queuetp.h"
#include "ListTP.h"
using namespace std;

int main()
{
	ListTP<int> cs(5);
	int temp;
	while (!cs.isfull())
	{
		cin >> temp;
		cs.push_back(temp);
	}
	cout << "List is full!\n";
	while (!cs.isempty())
	{
		cs.pop_front(temp);
		cout << "Now Processing " << temp << "...\n";
	}
    return 0;
}

