// 骰子模拟硬币翻转.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


bool Dice() {
	int x = (rand() % (6 - 1 + 1)) + 1;
	if (x == 1 || x == 2 || x == 3) return true;
	else 
		return false;
}
int main()
{
	srand(time(0));
	bool ans;
	for (int i = 1; i < 10; i++) {
		ans = Dice();
		if (ans == 1)	cout << "反面" << endl;
		else
			cout << "正面" << endl;
	}
    return 0;
}

