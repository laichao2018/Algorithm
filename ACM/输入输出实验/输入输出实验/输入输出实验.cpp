// 输入输出实验.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include<ctime>

const int M = 1e6;

int main()
{
	using namespace std;
	/**韩星点兵
	int n = 10;
	int a, b, c;
	int kase = 0;
	bool is_ans = false;
	while (scanf_s("%d%d%d", &a, &b, &c) == 3)
	{
		n = 10;
		is_ans = false;
		if (kase) printf("\n");
		for (; n <= 100; n++)
		{
			if (n % 3 == a && n % 5 == b && n % 7 == c)
			{
				printf("Case %d: %d", ++kase, n);
				is_ans = true;
			}
		}
		if (!is_ans) printf("Case %d: ", ++kase);
	}
	*/
	//倒三角
	/*
	int n = 0;
	int m = 0;
	while (scanf_s("%d",&n) == 1)
	{
		m = 0;
		for (; n > 0; n--)
		{
			int temp = 2 * n - 1;
			while (temp--) 
				printf("#");
			printf("\n");
			int space = ++m;
			//printf("%d %d ", space, m);
			while (space--)
				printf(" ");
		}
	}*/
	//子序列的和
	/**
	int n1, m1;
	int kase = 0;
	while (scanf_s("%d%d", &n1, &m1) == 2 && n1 && m1)
	{
		long long n = n1, m = m1;
		double ans = 0;
		for (int i = 0; i<= m; i++)
		{
			int temp = n + i;
			if (temp == m + 1) break;
			ans += 1 / pow(temp, 2);
		}
		printf("Case %d: %.5f", ++kase, ans);
	}
	*/
	//分数化小数
	int a, b, c;
	int kase = 0;
	while (scanf_s("%d%d%d", &a, &b, &c) == 3&& a&&b&&c)
	{
		float n = a, m = b;
		printf("Case %d: %.cf", ++kase, n / m);
	}
	return 0;
}

