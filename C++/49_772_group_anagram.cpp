#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Given an array of strings, group anagrams together.
Note:
All inputs will be in lowercase.
The order of your output does not matter.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]

解题思路：类似lint171
map保存单词key和vector
key可以通过对每个单词sort得到
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> anagrams;
		for (string s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			anagrams[key].push_back(s);
		}

		vector<vector<string>> results;
		for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
			results.push_back(it->second);
		}

		return results;
	}
};