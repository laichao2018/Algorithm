// 整数和.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	while (n)
	{
		ans += n % 10;
		n = n / 10;
	}
	cout << ans;
    return 0;
	
}

