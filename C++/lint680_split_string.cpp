#include "head.h"

/*
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example1
Input: "123"
Output: [["1","2","3"],["12","3"],["1","23"]]
Example2
Input: "12345"
Output: [["1","23","45"],["12","3","45"],["12","34","5"],["1","2","3","45"],["1","2","34","5"],["1","23","4","5"],["12","3","4","5"],["1","2","3","4","5"]]

解题思路：dfs
*/

class Solution {
public:
	vector<vector<string>> splitString(string& s) {
		if (s.empty()) return{ {} }; //易错

		vector<vector<string>> results;
		vector<string> combination;
		dfs(s, 0, combination, results);

		return results;
	}

	void dfs(string& s, int start, vector<string> &combination, vector<vector<string>> &results) {
		if (start >= s.size()) {
			results.push_back(combination);
			return;
		}

		for (int i = 1; i <= 2; i++) {
			if (start + i > s.size()) { //易错
				break;
			}

			combination.push_back(s.substr(start, i));
			dfs(s, start + i, combination, results);
			combination.pop_back();
		}
	}
};