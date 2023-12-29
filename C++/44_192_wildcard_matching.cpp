#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false

解题思路：双序列型dp，类似#10
state[i][j]表示s中的0~i-1和p中的0~j-1是否匹配
*/

class Solution {
public:
	bool isMatch(string &s, string &p) {
		int n = s.size();
		int m = p.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

		dp[0][0] = true; //空对空肯定匹配
		for (int j = 1; j <= m; j++) { //p与空string判断是否匹配，s与空string肯定不匹配不用特殊处理
			if ('*' == p[j - 1]) {	   //易错 j-1为下标
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if ('*' == p[j - 1]) {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; //*当成任意||空sequence
				}
				else if ('?' == p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = (p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
				}
			}
		}

		return dp[n][m];
	}
};