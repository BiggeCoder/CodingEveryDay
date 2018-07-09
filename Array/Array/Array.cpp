// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++)
		{
			int row[9] = {};
			int col[9] = {};
			int cube[9] = {};
			int temprow,tempcol,tempcube;
			for(int j = 0; j < 9; j++)
			{
				//行
				if(board[i][j] != '.')
				{
					temprow = board[j][i] - '1';
					if(row[board[i][j] - '1'] == 1)
					{
						return false;
					}
					else
					{
						row[board[i][j] - '1'] = 1;
					}
				}
				//列
				if(board[j][i] != '.')
				{
					tempcol = board[j][i] - '1';
					if(col[ board[j][i] - '1'] == 1)
					{
						return false;
					}
					else
					{
						col[ board[j][i] - '1'] = 1;
					}
				}
				//宫
				int x = 3*(i/3) + j/3;
				int y = 3*(i%3) + j%3;
				if(board[x][y] != '.')
				{
					tempcube = board[x][y] - '1';
					if(cube[ board[x][y] - '1'] == 1)
					{
						return false;
					}
					else
					{
						cube[ board[x][y] - '1'] = 1;
					}
				}
			}
		}
		return true;
	}
};

class Solution1 {
public:
	void swap(int &left, int &right)
	{
		int temp = left;
		left = right;
		right = temp;
	}

	void rotate(vector<vector<int>>& matrix) {
		int rowLen = matrix.size();
		for(int i = 0; i < rowLen; i++)
		{
			for(int j = i+1; j < rowLen; j++ )
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		int colLen = rowLen/2;
		for(int i = 0; i < rowLen; i++)
		{
			for(int j = 0; j < colLen; j++)
			{
				swap(matrix[i][j], matrix[i][rowLen-j-1]);
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> num;
	vector<int> temp;
	int row1[] = { 1,1,1};
	for (int i = 0; i < 3; i++)
	{
		temp.push_back(row1[i]);
	}
	num.push_back(temp);
	temp.clear();

	int row2[] = { 2,2,2};
	for (int i = 0; i < 3; i++)
	{
		temp.push_back(row2[i]);
	}
	num.push_back(temp);
	temp.clear();

	int row3[] = {3,3,3};
	for (int i = 0; i < 3; i++)
	{
		temp.push_back(row3[i]);
	}
	num.push_back(temp);
	temp.clear();

	

	//Solution().isValidSudoku(num);
	Solution1().rotate(num);

	return 0;
}

