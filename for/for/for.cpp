// for.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
	int a[10] = {0};
	for (const auto n : a)
		cout << n << " ";
    return 0; 
}

