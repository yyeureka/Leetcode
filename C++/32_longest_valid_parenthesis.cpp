#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

解题思路：dp
1、v[i]为以i元素结尾的长度
2、遍历i = 1~n-1：
   当为(时，长度为0
   当为)时，前一个没配对的位置pre为i-1-v[i-1]
		当s[pre]为(时，v[i] = v[i-1]+2，且需要加上v[pre-1]链接上pre前已配对好的
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		if (!n) return 0;

		int res = 0;
		vector<int> v(n, 0);
		for (int i = 1; i < n; i++) {
			if (')' == s[i]) {
				int pre = i - 1 - v[i - 1];
				if (pre >= 0 && '(' == s[pre]) { //要判断下标越界
					v[i] = v[i - 1] + 2;
					if (pre - 1 >= 0) v[i] += v[pre - 1]; //要判断下标越界
				}
			}
			res = max(res, v[i]);
		}
		return res;
	}
};

//void main()
//{
//	string s = "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
//	Solution so;
//	cout << so.longestValidParentheses(s) << endl;
//}