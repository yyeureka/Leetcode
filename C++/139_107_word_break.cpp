#include "head.h"

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

解题思路：
1、序列型dp
   v[n+1]，v[i]为前i-1是否能match
   v[i]为true的条件为：j从i-1到0遍历，v[j]为true，并且[j,i)能在dict中找到
2、dfs+memoization
3、dfs
*/

class Solution {
public:
	bool wordBreak(string &s, unordered_set<string> &dict) {
		if (s.empty()) {
			return true;
		}
		if (dict.empty()) {
			return false;
		}

		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (int i = 1; i <= s.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (!dp[j]) {
					continue;
				}
				if (dict.find(s.substr(j, i - j)) == dict.end()) {
					continue;
				}

				dp[i] = true;
				break; //易错
			}
		}

		return dp[s.size()];
	}
};

////dfs+memoization
//class Solution {
//public:
//	bool wordBreak(string &s, unordered_set<string> &dict) {
//		unordered_map<int, bool> memo; //以index为key比string好，查找时间复杂度是O(key的长度)
//		return dfs(s, 0, dict, memo);
//	}
//
//	bool dfs(string &s, int start, unordered_set<string> &dict, unordered_map<int, bool> &memo) {
//		if (start >= s.size()) {
//			return true;
//		}
//		if (dict.empty()) {
//			return false;
//		}
//		if (memo.find(start) != memo.end()) {
//			return memo[start];
//		}
//
//		memo[start] = false;
//		for (int i = 1; start + i <= s.size(); i++) {
//			if (dict.find(s.substr(start, i)) == dict.end()) {
//				continue;
//			}
//
//			if (dfs(s, start + i, dict, memo)) {
//				memo[start] = true;
//				break;
//			}
//		}
//
//		return memo[start];
//	}
//};

////dfs
//class Solution {
//public:
//	bool wordBreak(string &s, unordered_set<string> &dict) {
//		if (s.empty()) {
//			return true;
//		}
//		if (dict.empty()) {
//			return false;
//		}
//
//		for (int i = 1; i <= s.size(); i++) {
//			if (dict.find(s.substr(0, i)) == dict.end()) {
//				continue;
//			}
//
//			string next = s.substr(i);
//			if (wordBreak(next, dict)) {
//				return true;
//			}
//		}
//
//		return false;
//	}
//};