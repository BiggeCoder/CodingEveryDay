// String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//反转字符串
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

//颠倒整数
class Solution1 {
public:
    int reverse(int x) {
        int64_t reverseResult = 0;
        while(x != 0)
        {
            reverseResult = reverseResult*10 + x%10;
            x /= 10;
        }
        return (reverseResult < INT32_MIN || reverseResult > INT32_MAX) ? 0 : reverseResult;
    }
};

void TestSolution1()
{
    int a = 1234;
    int rev = Solution1().reverse(a);
}

//字符串中的第一个唯一字符
class Solution2 {
public:
    int firstUniqChar(string s) {
        if(0 == s.length())
        {
            return -1;
        }
        if(1 == s.length())
        {
            return 0;
        }
        //26个英文字母统计出现次数
        int elements[26] = {};
        for(size_t len = 0; len < s.length(); len++)
        {
            elements[ s[len] - 'a']++;
        }
        int uniqeCount = 0;
        int minUniqe = 0;
        for(int index = 0; index < 26; index++)
        {
            //寻找只出现一次的字母
            if(elements[index] == 1)
            {
                char uniqChar = 'a'+ index;
                for(int strloop = 0; strloop < s.length(); strloop++)
                {
                    //找出位置最靠前的唯一字母
                    if(uniqChar == s[strloop])
                    {
                        if(uniqeCount == 0)
                        {
                            //第一次找到唯一的字母
                            minUniqe = strloop;
                        }
                        else
                        {
                            if(minUniqe > strloop)
                            {
                                minUniqe = strloop;
                            }
                        }
                    }
                }
                uniqeCount++;
            }
        }
      return (uniqeCount>0)? minUniqe : -1 ;
    }
};

void TestSolution2()
{
    string str = "asdfasdfcaaaa";
    int first = Solution2().firstUniqChar(str);
}
//有效的字母异位词
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        int s1[26] = {};
        for(size_t index =0; index < s.length(); index++)
        {
            s1[ s[index] - 'a' ]++;
        }
        for(size_t index =0; index < t.length(); index++)
        {
            s1[ t[index] - 'a' ]--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(0 != s1[i])
            {
                return false;
            }
        }
        return true;
    }
};

void TestSolution3()
{
    string str1 = "asdfasdfcaaaa";
    string str2 = "asdfasdfacaaa";
    bool isAnagram = Solution3().isAnagram(str1,str2);
}

//验证回文字符串
class Solution4 {
public:
    void tolower(string &s)
    {
        for (string::iterator itor = s.begin(); itor != s.end(); itor++)
        {
            if (*itor >= 'A' && *itor <= 'Z')
            {
                *itor = *itor + 32;
            }
        }
    }

    bool isPalindrome(string s) {
        if(s.length() == 0)
        {
            return true;
        }
        int tail = s.length() - 1;
        int head = 0;
        string str = s;
        tolower(str);
        while( (head < tail) && (head < str.length() - 1) )
        {
            char a = str[head];
            char c = str[tail];
            bool f = (str[head] >= 'a');
            if(!(( (str[head] >= 'a') && (str[head] <= 'z')) || ( (str[head] >= '0') && (str[head] <= '9'))))
            {
                head++;
                continue;
            }

            if(!(( (str[tail] >= 'a') && (str[tail] <= 'z')) || ((str[tail] >= '0') && (str[tail] <= '9'))))
            {
                tail--;
                continue;
            }

            if(str[head] != str[tail])
            {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};

void TestSolution4()
{
    string str = "A man, a plan, a canal: Panama";
    bool isPalindrome = Solution3().isPalindrome(str);
}

//atoi转换
class Solution5 {
public:
    int valuedAtoi(vector<char> &value)
    {
        if(value.size() == 0)
        {
            return 0;           //无有效值
        }
        if(value.size() == 1)   //只有符号标志
        {
            if (value[0] == '+' || value[0] == '-')
            {
                return 0;
            }
            return value[0]-'0';
        }
        char signedChar = '+';
        int64_t sum = 0; 
        for( int i =0; i < value.size() ; i++)
        {
            char valuedChar = value[i];
            if(valuedChar == '+')
            {

            }
            else if(valuedChar == '-')
            {
                signedChar = '-';
            }
            else
            {
                int temp = valuedChar - '0';
                sum = sum*10 + temp;    //求总和
                int64_t  temp2 = sum - INT_MAX-1;
                if (temp2 >= 0)
                {
                    break;
                }
            }
        }

        int64_t max = sum - INT_MAX; //计算绝对值
        int64_t min = sum - INT_MAX-1;
        if(signedChar == '-')
        {
           if(max > 0)
           {
               return INT_MIN;
           }
            else
           {
               return -sum;
           }
        }
        else
        {
            if (min >= 0)
            {
                return INT_MAX;
            }
            
            return sum;
        }
    }

    int myAtoi(string str) {
        bool firstCharIsSigned = false; //第一个字符是符号标志
        bool hasValuedChar = false;     //已经有存储的有效数字
        vector<char> value;      //存储有效字符
        for(string::iterator itor = str.begin(); itor != str.end(); )
        {
            if(*itor == ' ')
            {
                if(hasValuedChar || firstCharIsSigned)
                {
                    break;
                }
                itor++;
                continue;
            }
            if(*itor == '+' || *itor == '-')
            {
                if(!firstCharIsSigned && !hasValuedChar)
                {
                    firstCharIsSigned = true;
                    value.push_back(*itor);
                    itor++;
                    continue;
                }
                break;
            }
            else if(*itor >= '0' && *itor <= '9')
            {
                hasValuedChar = true;  
                value.push_back(*itor);
                itor++;
                continue;
            }
            else
            {
                break;
            }
        }

        return valuedAtoi(value);
    }
};

void TestSolution5()
{
    string test ="18446744073709551617";
    int value = Solution10().myAtoi(test);
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSolution();
        TestSolution1();
        TestSolution2();
        TestSolution3();
        TestSolution4();
	return 0;
}

