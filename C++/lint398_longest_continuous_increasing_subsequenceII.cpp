#include "head.h"

/*
Given an integer matrix. Find the longest increasing continuous subsequence in this matrix and return the 
length of it.
The longest increasing continuous subsequence here can start at any position and go up/down/left/right.

Example 1:
Input:
[
[1, 2, 3, 4, 5],
[16,17,24,23,6],
[15,18,25,22,7],
[14,19,20,21,8],
[13,12,11,10,9]
]
Output: 25
Explanation: 1 -> 2 -> 3 -> 4 -> 5 -> ... -> 25 (Spiral from outside to inside.)
Example 2:
Input:
[
[1, 2],
[5, 3]
]
Output: 4
Explanation: 1 -> 2 -> 3 -> 5

Challenge
Assume that it is a N x M matrix. Solve this problem in O(NM) time and memory.

����˼·��dp+dfs
1��dp[i][j]Ϊ��i��jΪ���ĳ���
2����ÿ��i��jΪ�����;���µķ�����TLE
*/

class Solution {
public:
	int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}

		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
		int maxLen = 0;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				dfs(matrix, dp, i, j);
				maxLen = max(maxLen, dp[i][j]);
			}
		}

		return maxLen;
	}

	void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y) {
		if (-1 != dp[x][y]) {
			return;
		}

		dp[x][y] = 1;
		vector<vector<int>> delta = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };

		for (auto i : delta) {
			int nextX = x + i[0];
			int nextY = y + i[1];

			if (nextX < 0 || nextX >= matrix.size() || nextY < 0 || nextY >= matrix[0].size() || matrix[nextX][nextY] <= matrix[x][y]) {
				continue;
			}

			dfs(matrix, dp, nextX, nextY);
			dp[x][y] = max(dp[x][y], dp[nextX][nextY] + 1);
		}
	}
};

//dfs TLE
//class Solution {
//public:
//	int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
//		if (matrix.empty() || matrix[0].empty()) {
//			return 0;
//		}
//
//		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
//		int maxLen = 0;
//
//		for (int i = 0; i < matrix.size(); i++) {
//			for (int j = 0; j < matrix[0].size(); j++) {
//				dfs(matrix, dp, i, j, maxLen);
//			}
//		}
//
//		return maxLen;
//	}
//
//	void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y, int &maxLen) {
//		maxLen = max(maxLen, dp[x][y]);
//
//		vector<vector<int>> delta = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
//		for (auto i : delta) {
//			int nextX = x + i[0];
//			int nextY = y + i[1];
//
//			if (nextX < 0 || nextX >= matrix.size() || nextY < 0 || nextY >= matrix[0].size() || matrix[nextX][nextY] <= matrix[x][y] || dp[nextX][nextY] > dp[x][y] + 1) {
//				continue;
//			}
//
//			dp[nextX][nextY] = dp[x][y] + 1;
//			dfs(matrix, dp, nextX, nextY, maxLen);
//		}
//	}
//};