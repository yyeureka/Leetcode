#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

解题思路：
序列型dp，注意与#5的区别

对于任意字符串:
如果头尾字符相同，最长子序列等于去掉首尾的字符串的最长子序列加上首尾
如果首尾字符不同，最长子序列等于去掉头的字符串的最长子序列和去掉尾的字符串的最长子序列的较大者。

s[i] == s[j]: dp[i][j] = dp[i + 1][j - 1] + 2;
s[i] != s[j]: dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
*/

class Solution {
public:
	/**
	* @param s: the maximum length of s is 1000
	* @return: the longest palindromic subsequence's length
	*/
	int longestPalindromeSubseq(string &s) {
		int size = s.size();
		if (!size) return 0;

		vector<vector<int>> dp(size, vector<int>(size, 0));

		for (int i = size - 1; i >= 0; i--) {
			for (int j = i; j < size; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] + 2 : j - i + 1;
				}
				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}

		return dp[0][size - 1];
	}
};