#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
Input: nums =
[
[9,9,4],
[6,6,8],
[2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:
Input: nums =
[
[3,4,5],
[3,2,6],
[2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

解题思路：
2、dfs，单纯dfs会TLE，二维数组记录计算过的结果
*/

class Solution {
public:
	int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &v) {
		if (v[row][col] > 0) return v[row][col];

		int res = 0;
		int cur = matrix[row][col];
		if (row > 0 && matrix[row - 1][col] > cur) res = max(res, dfs(matrix, row - 1, col, v));
		if (row < (matrix.size() - 1) && matrix[row + 1][col] > cur) res = max(res, dfs(matrix, row + 1, col, v));
		if (col > 0 && matrix[row][col - 1] > cur) res = max(res, dfs(matrix, row, col - 1, v));
		if (col < (matrix[0].size() - 1) && matrix[row][col + 1] > cur) res = max(res, dfs(matrix, row, col + 1, v));

		res += 1;
		v[row][col] = res;
		return res;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;

		vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));

		int res = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				res = max(res, dfs(matrix, i, j, v));
			}
		}
		return res;
	}
};