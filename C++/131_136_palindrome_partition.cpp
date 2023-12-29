#include <vector>
#include <unordered_map>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]

解题思路：类似#140
1、dfs+memoization
2、dfs 
*/

class Solution {
public:
	vector<vector<string>> partition(string &s) {
		unordered_map<string, vector<vector<string>>> memo;
		return dfs(s, memo);
	}

	vector<vector<string>> dfs(string &s, unordered_map<string, vector<vector<string>>> &memo) {
		if (s.empty()) {
			return{ {} };
		}
		if (1 == s.size()) {
			return{ { s } };
		}
		if (memo.find(s) != memo.end()) {
			return memo[s];
		}

		vector<vector<string>> results;

		for (int i = 0; i < s.size(); i++) {
			string left = s.substr(0, i);
			string right = s.substr(i);

			if (!isPalindrome(right)) {
				continue;
			}

			vector<vector<string>> tmp = dfs(left, memo);

			for (vector<string> j : tmp) {
				j.push_back(right);
				results.push_back(j);
			}
		}

		memo[s] = results;
		return results;
	}

	bool isPalindrome(string s) {
		int i = 0;
		int j = s.size() - 1;

		while (i < j) {
			if (s[i++] != s[j--]) {
				return false;
			}
		}

		return true;
	}
};

////dfs
//class Solution {
//public:
//	vector<vector<string>> partition(string &s) {
//		if (s.empty()) {
//			return{ {} };
//		}
//
//		vector<vector<string>> results;
//		vector<string> combination;
//		dfs(s, 0, combination, results);
//
//		return results;
//	}
//
//	void dfs(string &s, int start, vector<string> &combination, vector<vector<string>> &results) {
//		if (start >= s.size()) {
//			results.push_back(combination);
//			return;
//		}
//
//		for (int i = 1; i + start <= s.size(); i++) {
//			string substring = s.substr(start, i);
//
//			if (isPalindrome(substring)) {
//				combination.push_back(substring);
//				dfs(s, start + i, combination, results);
//				combination.pop_back();
//			}
//		}
//	}
//
//	bool isPalindrome(string s) {
//		int i = 0;
//		int j = s.size() - 1;
//
//		while (i < j) {
//			if (s[i++] != s[j--]) {
//				return false;
//			}
//		}
//
//		return true;
//	}
//};