#include <string>
#include <vector>
using namespace std;

/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

Example 1:
Input: "3+2*2"
Output: 7
Example 2:
Input: " 3/2 "
Output: 1
Example 3:
Input: " 3+5 / 2 "
Output: 5

解题思路：
1、
2、stack保存所有+/-的数，-的取负存进去
   乘/除的计算好再存进去
*/

class Solution {
public:
	int calculate(string s) {
		if (s.empty()) return 0;

		int res = 0;
		int cur_res = 0;
		char op = '+';
		int i = 0;
		while (i < s.size()) {
			if (' ' == s[i]) i++;
			else if (isdigit(s[i])) {
				int num = 0;
				while (i < s.size() && isdigit(s[i])) {
					num = num * 10 + (s[i] - '0');
					i++;
				}

				if ('+' == op) cur_res += num;
				else if ('-' == op) cur_res -= num;
				else if ('*' == op) cur_res *= num;
				else if ('/' == op) cur_res /= num;
			}
			else {
				op = s[i++];
				if ('+' == op || '-' == op) {
					res += cur_res;
					cur_res = 0;
				}
			}
		}
		return res + cur_res;
	}
};

//class Solution {
//public:
//	int calculate(string s) {
//		if (s.empty()) return 0;
//
//		vector<int> formula;
//		char op = '+';
//		int i = 0;
//		while (i < s.size()) {
//			if (' ' == s[i]) i++;
//			else if (isdigit(s[i])) {
//				int num = 0;
//				while (i < s.size() && isdigit(s[i])) {
//					num = num * 10 + (s[i] - '0'); //这个括号不能省，先加后减可能overflow
//					i++;
//				}
//
//				if ('+' == op) formula.push_back(num);
//				else if ('-' == op) formula.push_back(-num);
//				else if ('*' == op) formula.back() *= num;
//				else if ('/' == op) formula.back() /= num;
//			}
//			else op = s[i++];
//		}
//
//		int res = 0;
//		for (int i : formula) res += i;
//		return res;
//	}
//};