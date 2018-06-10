// 八皇后问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int g_count = 0;

bool IsLegal(int row, int col,bool spot_taken[][8])
{
	for (int i = 0; i < 8; i++) 
	{
		if (spot_taken[i][col] == 1) return false;
		if (spot_taken[row][i] == 1) return false;
	}
	for (int i = 0; i < 8; i++)                            // 左上
	{
		if (row - i < 0 || col - i < 0) break;
		if (spot_taken[row-i][col-i] == 1)
		{
			return false;
		}
	}
	for (int i = 0; i < 8; i++)                            //右上
	{
		if (row - i < 0 || col + i > 7) break;
		if (spot_taken[row - i][col + i] == 1) return false;
	}
	for (int i = 0; i < 8; i++)                           //左下
	{
		if (row + i > 7 || col - i < 0) break;
		if (spot_taken[row + i][col - i] == 1) return false;
	}
	for (int i = 0; i < 8; i++)                            //右下
	{
		if (row + i > 7 || col + i > 7) break;
		if (spot_taken[row + i][col + i] == 1) return false;
	}
	return true;
}

void EightQueens(int row, int col, bool spot_token[8][8])
{
	bool spot_taken2[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			spot_taken2[i][j] = spot_token[i][j];
		}
	}

	if (row == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << spot_taken2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		g_count++;
	}
	else
	{
		for (int j = 0; j < 8; j++)
		{
			if (IsLegal(row, j, spot_taken2))
			{
				spot_taken2[row][j] = 1;
				EightQueens(row + 1, j, spot_taken2);
				spot_taken2[row][j] = 0;
			}
		}
	}
}
void print(bool spot_taken[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << spot_taken[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	bool spot_taken[8][8] = { {0} };
	//print(spot_taken);
	//cout << endl;
	EightQueens(0,0,spot_taken);
	cout << g_count << endl;
	//print(spot_taken);
    return 0;
}

