#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

我理解错的地方：
1、.应该不会代替*
2、*应该不会单独出现，跟字符是匹配的，所以应该不会有**的情况
3、*不能无限替换下去，到下一个字母能对应上为止：aaa和a*a，aaaa和a*a

解题思路：双序列型dp，#44的follow up
1.当pattern为空时，string为空时true，否则为false
2.match = (string是否为空) && ((当前位是否相等) || (p当前位是否为.))
3.下一位是*时，判断p下2位与s当前位是否match（*0）||当前位match时，s下一位是否match p当前位（*n）:
  否则，如果当前match，对s、p下一位进行判断:

1.动态规划：
state[i][j]为i-1和j-1及其之前是否匹配

2.递归：
match = (string是否为空) && ((s[0] == p[0]) || (p[0]为.)) 
下一位是*：return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p))
否则：return match && isMatch(s.substr(1), p.substr(1))
*/

class Solution {
public:
	bool isMatch(string &s, string &p) {
		int n = s.size();
		int m = p.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

		dp[0][0] = true;
		for (int j = 2; j <= m; j++) { //易错 <=
			if ('*' == p[j - 1]) {     //易错 j-1
				dp[0][j] = dp[0][j - 2];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j > 1 && '*' == p[j - 1]) { //易错，j要>=2
					dp[i][j] = ((s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j]) || dp[i][j - 2]; //*对1或多||*对空
				}
				else if ('.' == p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
				}
			}
		}

		return dp[n][m];
	}
};