#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

解题思路：
recursion：
如果str长度等于2*n，完成一种组合
如果左括号小于n，加左括号递归
如果右括号小于左括号，加右括号递归
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0) return{};

		vector<string> results;
		string combination = "";
		dfs(n, 0, 0, combination, results);

		return results;
	}

	void dfs(int n, int left, int right, string combination, vector<string> &results) {
		if (2 * n == combination.size()) {
			results.push_back(combination);
			return;
		}

		if (left < n) {
			dfs(n, left + 1, right, combination + '(', results);
		}
		if (right < left) {
			dfs(n, left, right + 1, combination + ')', results);
		}
	}
};