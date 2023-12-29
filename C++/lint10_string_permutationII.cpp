#include "head.h"

/*
Given a string, find all permutations of it without duplicates.

Example 1:
Input: "abb"
Output:
["abb", "bab", "bba"]
Example 2:
Input: "aabb"
Output:
["aabb", "abab", "baba", "bbaa", "abba", "baab"]

解题思路：
#47 permutationsII换汤不换药
*/

class Solution {
public:
	vector<string> stringPermutation2(string &str) {
		vector<string> result;
		string cur = "";
		vector<bool> used(str.size(), false);

		sort(str.begin(), str.end());
		helper(str, used, cur, result);

		return result;
	}

	void helper(string &str, vector<bool> &used, string &cur, vector<string> &result) {
		if (str.size() == cur.size()) {
			result.push_back(cur);
			return;
		}

		for (int i = 0; i < str.size(); i++) {
			if (used[i]) continue;
			if (i > 0 && str[i] == str[i - 1] && !used[i - 1]) continue;

			cur += str[i];
			used[i] = true;
			helper(str, used, cur, result);
			used[i] = false;
			cur.erase(cur.size() - 1);
		}
	}
};