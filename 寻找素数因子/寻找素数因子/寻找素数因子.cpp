// 寻找素数因子.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
using namespace std;

void Run(int number, vector<int> &ans) {
	int i = 2;
	int j = 0;
	while (i < number) {
		while (number % i == 0) {
			ans.push_back(i);
			number = number / i;
		}
		i++;
	}
	if (number > 1)
		ans.push_back(number);
}
int main()
{
	int number;
	while(cin >> number){
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

