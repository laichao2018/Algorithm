// 素筛法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void Sieve(long max_number) {
	int i;
	bool* is_composite = new bool[max_number + 1];
	for (int j = 0; j <= max_number; j++)
		is_composite[j] = false;
	for (int i = 4; i <= max_number; i += 2) {
		is_composite[i] = true;
	}
	int next_prime = 3;
	int stop_at = sqrt(max_number);
	while (next_prime < stop_at)
	{
		for (int i = next_prime * 2; i <= max_number; i += next_prime)
			is_composite[i] = true;
		next_prime = next_prime + 2;
		while ((next_prime <= max_number) && (is_composite[next_prime]))
		{
			next_prime = next_prime + 2;
		}
	}
	vector<int> ans;
	for (int i = 2; i <= max_number; i++) {
		if (!is_composite[i])
			ans.push_back(i);
	}
	//cout << " asdf";
	int j;
	//cout << ans.size() << endl;
	for (j = 0; j < ans.size(); j++) {
		cout << ans[j] << " ";
	}
}

int main()
{
	long max_number;
	while(cin >> max_number)
		Sieve(max_number);
    return 0;
}

