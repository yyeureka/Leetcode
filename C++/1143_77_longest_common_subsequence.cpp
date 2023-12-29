#include "head.h"

/*
Given two strings, find the longest common subsequence (LCS).
Your code should return the length of LCS.

Example 1:
Input:  "ABCD" and "EDCA"
Output:  1
Explanation:
LCS is 'A' or  'D' or 'C'
Example 2:
Input: "ABCD" and "EACB"
Output:  2
Explanation:
LCS is "AC"

Clarification
What's the definition of Longest Common Subsequence?
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm

解题思路：
dp[i][j]为A[0]~A[i-1]和B[0]~B[j-1]中LCS长度
*/

class Solution {
public:
	int longestCommonSubsequence(string &A, string &B) {
		if (A.empty() || B.empty()) {
			return 0;
		}

		int n = A.size();
		int m = B.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i - 1] == B[j - 1]) { //易错
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[n][m];
	}
};