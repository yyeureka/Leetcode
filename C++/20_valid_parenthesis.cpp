#include <string>
#include <vector>
using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true
Example 2:
Input: "()[]{}"
Output: true
Example 3:
Input: "(]"
Output: false
Example 4:
Input: "([)]"
Output: false
Example 5:
Input: "{[]}"
Output: true

要注意的点：
1、当前为反括号，buffer为空时，false，pop出的不是匹配的正括号，false
2、来的不是括号，false
3、最后buffer不为空，false
*/

class Solution {
public:
	bool isValid(string s) {
		vector<int> buf;
		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '(':
				buf.push_back(')');
				break;
			case '[':
				buf.push_back(']');
				break;
			case '{':
				buf.push_back('}');
				break;
			case ')':
			case ']':
			case '}':
				if ((buf.empty()) || (buf.back() != s[i])) return false;
				buf.pop_back();
				break;
			}
		}
		return buf.empty();
	}
};