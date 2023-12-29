#include "head.h"

/*
Given an array of strings, return all groups of strings that are anagrams.

Example 1:
Input:["lint", "intl", "inlt", "code"]
Output:["lint", "inlt", "intl"]
Example 2:
Input:["ab", "ba", "cd", "dc", "e"]
Output: ["ab", "ba", "cd", "dc"]

Challenge
What is Anagram?
Two strings are anagram if they can be the same after change the order of characters.

Notice
All inputs will be in lower-case

解题思路：类似#49
*/

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		if (strs.empty()) return{};

		unordered_map<string, vector<string>> anagrams;
		for (string s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			anagrams[key].push_back(s);
		}

		vector<string> results;
		for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
			if (it->second.size() <= 1) continue;

			for (string s : it->second) {
				results.push_back(s);
			}
		}

		return results;
	}
};