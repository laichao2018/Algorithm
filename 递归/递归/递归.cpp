// 递归.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int Factorial(unsigned long long n)
{
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}
int Fibonacci(int n)
{
	if (n <= 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
	short n;
	/*
	while (std::cin >> n)
	{
		std::cout << Factorial(n) << "\n";
	}
	*/
	int m;
	while (std::cin >> m)
	{
		std::cout << Fibonacci(m) << " " << "\n";
	}
    return 0;
}

