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

����˼·��
������dp��ע����#5������

���������ַ���:
���ͷβ�ַ���ͬ��������е���ȥ����β���ַ�����������м�����β
�����β�ַ���ͬ��������е���ȥ��ͷ���ַ�����������к�ȥ��β���ַ�����������еĽϴ��ߡ�

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