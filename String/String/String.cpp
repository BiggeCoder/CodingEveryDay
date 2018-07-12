// String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "stdint.h"
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
    bool isPalindrome = Solution4().isPalindrome(str);
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
    int value = Solution5().myAtoi(test);
}

//实现strStr
class Solution6 {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0 )
        {
            return 0;
        }
        if(needle.size() > haystack.size())
        {
            return -1;
        }
        int substrlen = needle.size();
        int haystacklen = haystack.size();
        for( int startlen = 0, endlen = substrlen; endlen <= haystacklen; )
        {
            string substr;  //起始位置和结束位置相同，列：两个字符串都只有一个字符
            if (startlen == endlen)
            {
                substr = haystack[startlen];
            } 
            else
            {
                substr = haystack.substr(startlen, endlen); 
            }
            if( memcmp(substr.c_str(),needle.c_str(),needle.size()) == 0 )
            {
                return startlen;
            }
            startlen++;
            endlen++;
        }
        return -1;
    }
};

void TestSolution6()
{
	string a = "aaa";
	string b = "aa";
	int index = Solution6().strStr(a,b);
}

//数数并说
class Solution7 {
public:
	
    //思想，统计上一个数的各个数字出现的次数，将次数和对应的值记录下来，
    //如： 4：1211
    //则： 5：从左往右统计4对应的值，出现1个1，1个2，2个1； 
    //结果 5：111221
   string countAndSay(int n) {
    string s="1";
    int count=1;
    while(n>1)
    {
        string tmp="";
        for(int i=0;i<s.size();)
        {
            int j=i+1;
            for(;j<s.size();++j)
            {
                if (s[i] == s[j])
                {
                    count++;
                } 
                else
                {
                    break;
                }
            } 
            tmp.push_back(char(count+'0'));
            tmp.push_back(s[i]);
            i=j;
            count=1;
        } 
        n--;
        s=tmp;
    }
    return s;
        }
};

void TestSolution7()
{
    string result = Solution7().countAndSay(5);
}

class Solution8 {
public:
     string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1)
        {
            return "";
        }
        else if(strs.size() == 1)
        {
            return strs[0];
        }
        string comPrefix = strs[0];
        int comIndex = comPrefix.size();
        for(vector<string>::iterator itor = strs.begin()+1; itor != strs.end(); itor++)
        {
            for(int strlen = 0; (strlen < comIndex); strlen++)
            {
                if (!(strlen < (*itor).size()))
                {
                    comIndex = strlen;
                    break;
                }
                if(comIndex <= 0)
                {
                    return "";
                }
                char left = (*itor).c_str()[strlen];
                char right = comPrefix.c_str()[strlen];
                if( left != right )
                {
                    comIndex = strlen ;
                }
            }
        }
        string result = "";
        for(int i = 0; i < comIndex; i++)
        {
            result.push_back(comPrefix[i]);
        }
        return result;
    }
};

void TestSolution8()
{
     vector<string> test;
     test.push_back("asdfg");
     test.push_back("asdf");
     string result = Solution8().longestCommonPrefix(test);
}


 //Definition for singly-linked list.
 struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution9 {
public:
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *myHead = new ListNode(0);
		myHead->next = head;
        ListNode *preNode = myHead;
        ListNode *curNode = myHead;
        for(int i = 0; i < n; i++)
        {
            //已保证输入有效
            preNode = preNode->next;
        }
		while(preNode->next != NULL ) 
		{
			preNode = preNode->next;
			curNode = curNode->next;
		}
		preNode = curNode->next;
		curNode->next = curNode->next->next;
        return head;     
    }
};

void TestSolution9()
	{
	ListNode *a1 = new ListNode(1);
 	ListNode *a2 = new ListNode(2);
 	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
 	ListNode *a5 = new ListNode(5);
 	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
 	a4->next = a5;
	Solution9().removeNthFromEnd(a1,2);

}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSolution();
	TestSolution1();
	TestSolution2();
	TestSolution3();
	TestSolution4();
	TestSolution5();
	TestSolution6();
	TestSolution7();
	TestSolution8();
	TestSolution9();
	return 0;
}

