// 费马小定理.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;

bool IsPrime(int P, int max_tests) {
	int n;
	for (int test = 1; test <=max_tests; test++) {
		n = rand() % (P-1)+1;
		//printf("%d \t %.9lf \t %d \n", n, pow(double(n), (double)(P - 1)), (long long)pow(double(n), (double)(P - 1)) % P);
		long long t = pow(double(n), (double)(P - 1));
		if (t % P != 1) return false;
	}
	return true;
}

int main()
{
	srand(time(0));
	int p;
	while (cin >> p) {
		bool ans = IsPrime(p, 1000);
		cout << ans << " ";
	}
    return 0;
}

