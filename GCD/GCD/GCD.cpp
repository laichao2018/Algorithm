// GCD.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

/*
vector<int> Prime_Factor(int n) {
vector<int> ans;
for (int i = 2; i <= n; i++) {
if (n % i == 0) {
n /= i;
ans.pb(i);
i--;
}
}
return ans;
}

*/
/*
vector<int> public_num(vector<int> num1, vector<int> num2) {
int length1 = num1.size();
int length2 = num2.size();
vector<int> public_num;
//if (length1 < length2) {
for (int i = 0; i < length2; i++) {
for (int j = 0; j < length2; j++) {
if (num1[i] != num2[2])
public_num.pb(num1[i]);
}
}
//}
}
*/
int __gcd(int num1,int num2) {
	int ans;
	int k;
	do
	{
		k = num1 % num2;
		num1 = num2;
		num2 = k;
		//cout << k << endl;
	} while (k != 0);
	ans = num1;
	return ans;
}
int main()
{
	//vector<int> final_ans;
	//int num;
/*
//一个数的质因数
cin >> num;
final_ans = Prime_Factor(num);
for (int i = 0; i < final_ans.size(); i++)
cout << final_ans[i] << " ";
cout << '\n';
*/
	//最大公约数
	int num1, num2;
	int answer;
	while (cin >> num1 >> num2) {
		answer = __gcd(num1, num2);
		cout << answer << " ";
	}
	cout << '\n';
    return 0;
}

