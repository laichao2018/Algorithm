// 选择与排列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

list<string> Select3WithDuplicates(list<string> items)
{
	list<string> *result = new list<string>;
	int length = items.size();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			for (int k = 0; k < length; k++)
			{
				result->push_back(items[i] + items[j] + items[k]);
			}
		}
	}
}

int main()
{
    return 0;
}

