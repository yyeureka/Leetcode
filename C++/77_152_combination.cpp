#include <vector>
using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2
Output:
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

解题思路：dfs
以4 2为例
1 2
1 3
1 4
2 3
2 4
3 4
*/

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> cur;
		dfs(n, k, res, cur);
		return res;
	}

	void dfs(int n, int k, vector<vector<int>> &res, vector<int> &cur) {
		if (cur.size() >= k) {
			res.push_back(cur);
			return;
		}

		int min = cur.empty() ? 0 : cur.back();
		for (int i = min + 1; i <= n; i++) {
			cur.push_back(i);
			dfs(n, k, res, cur);
			cur.pop_back();
		}
	}
};

//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		if (n <= 0 || k <= 0) return{ {} };
//
//		vector<vector<int>> results;
//		vector<int> combination;
//		dfs(n, k, 1, combination, results);
//
//		return results;
//	}
//
//	void dfs(int n, int k, int start, vector<int> &combination, vector<vector<int>> &results) {
//		if (combination.size() == k) {
//			results.push_back(combination);
//			return;
//		}
//
//		for (int i = start; i <= n; i++) {
//			combination.push_back(i);
//			dfs(n, k, i + 1, combination, results);
//			combination.pop_back();
//		}
//	}
//};