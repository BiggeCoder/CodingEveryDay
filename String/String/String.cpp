// String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string reversString;
		for (int len = s.length()-1; len >= 0; len--)
		{
			reversString.push_back(s[len]);
		}
		return reversString;
	}
};

void TestSolution()
{
	string st = "hello";
	string reversSt = Solution().reverseString(st);
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSolution();
	return 0;
}

