#include "head.h"

/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

Example 1
Input:
pattern = "abab"
str = "redblueredblue"
Output: true
Explanation: "a"->"red","b"->"blue"
Example 2
Input:
pattern = "aaaa"
str = "asdasdasdasd"
Output: true
Explanation: "a"->"asd"
Example 3
Input:
pattern = "aabb"
str = "xyzabcxzyabc"
Output: false

Notice
You may assume both pattern and str contains only lowercase letters.

����˼·��
������dfs��map��¼key��word��set��¼�Ѿ�ƥ���key��word
*/

class Solution {
public:
	bool wordPatternMatch(string &pattern, string &str) {
		unordered_map<char, string> dict; //key:word
		unordered_set<string> words;      //����key��word
		return dfs(pattern, str, dict, words);
	}

	bool dfs(string pattern, string str, unordered_map<char, string> &dict, unordered_set<string> &words) {
		if (pattern.empty() || str.empty()) { //�״�
			if (pattern.empty() && str.empty()) {
				return true;
			}

			return false;
		}

		char key = pattern[0];

		if (dict.find(key) != dict.end()) {
			string word = dict[key];

			if (word != str.substr(0, word.size())) {
				return false;
			}
			return dfs(pattern.substr(1), str.substr(word.size()), dict, words);
		}

		for (int i = 1; i <= str.size(); i++) {
			string word = str.substr(0, i);

			if (words.find(word) != words.end()) { //�ؼ�
				continue;
			}

			words.insert(word); //�״�
			dict[key] = word;

			if (dfs(pattern.substr(1), str.substr(word.size()), dict, words)) {
				return true;
			}

			dict.erase(key);
			words.erase(word);
		}

		return false;
	}
};