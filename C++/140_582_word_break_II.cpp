#include "head.h"

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
"cats and dog",
"cat sand dog"
]
Example 2:
Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
"pine apple pen apple",
"pineapple pen apple",
"pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:
Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

解题思路：类似#131
1、dfs+memoization
2、dfs会TLE
*/

class Solution {
public:
	vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
		if (s.empty() || wordDict.empty()) {
			return{};
		}

		unordered_map<string, vector<string>> memo; //改成key貌似还慢了
		return dfs(s, wordDict, memo);
	}

	vector<string> dfs(string &s, unordered_set<string> &wordDict, unordered_map<string, vector<string>> &memo) {
		if (s.empty()) {
			return{};
		}
		if (memo.find(s) != memo.end()) {
			return memo[s];
		}

		vector<string> results;

		if (wordDict.find(s) != wordDict.end()) { //1.保证返回空的时候只有match失败一种情况 2.减少递归次数
			results.push_back(s);
		}

		for (int i = 1; i < s.size(); i++) {
			string left = s.substr(0, i);
			string right = s.substr(i);

			if (wordDict.find(right) == wordDict.end()) {
				continue;
			}

			vector<string> tmp = dfs(left, wordDict, memo);

			for (string j : tmp) {
				results.push_back(j + " " + right);
			}
		}

		memo[s] = results;
		return results;
	}
};