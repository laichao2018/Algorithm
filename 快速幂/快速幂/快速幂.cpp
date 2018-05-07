// 快速幂.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
using namespace std;
int Raise(float A, int P) {
	int n = 1;
	int ans = 1;
	while (P != 0) {
		if (P & 1)
			ans = ans * A;
		A = A * A;
		P = P >> 1;
	}
	return ans;
}
int main()
{
	float A;
	int P;
	cin >> A >> P;
	float answ = Raise(A, P);
	cout << answ;
	return 0;
}