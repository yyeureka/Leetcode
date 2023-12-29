#include "head.h"

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

解题思路：
1、Enumerate：对每一个s[i]，从i-1和i+1开始向两边扩展判断，从i和i+1开始向两边扩展判断
2、dp：dp[i][j]为从i~j是否回文，条件是s[i]==s[j]并且dp[i+1][j-1]为true，空间和时间都非常低效！！
3、O(n)的Manancher's Algorithm：https://segmentfault.com/a/1190000003914228
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0;
		int len = 0;

		for (int i = 0; i < s.size(); i++) {
			int l = i - 1;
			int r = i + 1;
			while (l >= 0 && r < s.size() && s[l] == s[r]) {
				l--;
				r++;
			}
			if (r - l - 1 > len) {
				len = r - l - 1;
				start = l + 1;
			}

			l = i;
			r = i + 1;
			while (l >= 0 && r < s.size() && s[l] == s[r]) {
				l--;
				r++;
			}
			if (r - l - 1 > len) {
				len = r - l - 1;
				start = l + 1;
			}
		}
		return s.substr(start, len);
	}
};

//class Solution {
//public:
//	string longestPalindrome(string &s) {
//		int n = s.size();
//		if (!n) return "";
//
//		int start = 0;
//		int len = 0;
//		vector<vector<bool>> dp(n, vector<bool>(n, false));
//
//		for (int i = n - 1; i >= 0; i--) {
//			for (int j = i; j < n; j++) {
//				if (s[i] != s[j]) continue;
//
//				dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true; //i + 1 < j关键点
//
//				if (dp[i][j] && j - i + 1 > len) { //易错 dp[i][j]不能漏
//					len = j - i + 1;
//					start = i;
//				}
//			}
//		}
//		return s.substr(start, len);
//	}
//};