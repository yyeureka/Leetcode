#include "head.h"

/*
Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Example1
Input:
"CatMat"
["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
Output: 3
Explanation:
we can form 3 sentences, as follows:
"CatMat" = "Cat" + "Mat"
"CatMat" = "Ca" + "tM" + "at"
"CatMat" = "C" + "at" + "Mat"
Example1
Input:
"a"
[]
Output: 0

Notice
Ignore case

解题思路：序列型dp
1、straightforward
2、设dp[i][j]表示从字典dict中组成子串str[i:j+1]有多少种方法。
   转移方程为：dp[i][j] = ∑{k=i~j} dp[i][k]*dp[k+1][j]
*/

class Solution {
public:
	int wordBreak3(string& s, unordered_set<string>& dict) {
		if (s.empty() || dict.empty()) {
			return 0;
		}

		string input = toLower(s);
		unordered_set<string> lowerDict;
		for (string i : dict) {
			lowerDict.insert(toLower(i));
		}

		vector<int> dp(input.size() + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= input.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (0 == dp[j]) {
					continue;
				}
				if (lowerDict.find(input.substr(j, i - j)) == lowerDict.end()) {
					continue;
				}

				dp[i] += dp[j];
			}
		}

		return dp[input.size()];
	}

	string toLower(string &s) {
		string output = "";

		for (char c : s) {
			if (c >= 'A' && c <= 'Z') {
				c -= 'A' - 'a';
			}
			output += c;
		}

		return output;
	}
};

//class Solution {
//public:
//	int wordBreak3(string& s, unordered_set<string>& dict) {
//		if (s.empty() || dict.empty()) {
//			return 0;
//		}
//
//		string lowerS = toLower(s);
//		unordered_set<string> lowerDict;
//		for (string i : dict) {
//			lowerDict.insert(toLower(i));
//		}
//
//		int n = lowerS.size();
//		vector<vector<int>> dp(n, vector<int>(n, 0));
//
//		for (int i = 0; i < n; i++) {
//			for (int j = i; j < n; j++) {
//				if (lowerDict.find(lowerS.substr(i, j - i + 1)) != lowerDict.end()) {
//					dp[i][j] = 1;
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = i; j < n; j++) {
//				for (int k = i; k < j; k++) {
//					dp[i][j] += (dp[i][k] * dp[k + 1][j]);
//				}
//			}
//		}
//		return dp[0][n - 1];
//	}
//
//	string toLower(string &s) {
//		string lower = "";
//
//		for (char c : s) {
//			if (c >= 'A' && c <= 'Z') {
//				c -= 'A' - 'a';
//			}
//			lower += c;
//		}
//
//		return lower;
//	}
//};

