// 寻找素因子优化算法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
using namespace std;

void Run(int number, vector<int> &ans) {
	while (number % 2 == 0) {
		ans.push_back(2);
		number = number / 2;
	
	}
	int i = 3;
	int max_s = sqrt(number);
	while (i < max_s) {
		while (number % i == 0) {
			ans.push_back(i);
			number = number / i;
		}
		i += 2;
		max_s = sqrt(number);
	}
	if (number > 1)	ans.push_back(number);
}
int main()
{
	int number;
	while (cin >> number) {
		vector<int> ans;
		Run(number, ans);
		int len = ans.size();
		for (int i = 0; i < len; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}