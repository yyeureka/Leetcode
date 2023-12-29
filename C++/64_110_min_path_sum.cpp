#include <vector>
#include <algorithm>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
[1,3,1],
[1,5,1],
[4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

解题思路：坐标型dp
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}

		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				}
				if (j > 0) {
					dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				}

				dp[i][j] = INT_MAX == dp[i][j] ? grid[i][j] : dp[i][j] + grid[i][j];
			}
		}

		return dp[n - 1][m - 1];
	}
};

////滚动数组
//class Solution {
//public:
//	int minPathSum(vector<vector<int>> &grid) {
//		if (grid.empty() || grid[0].empty()) {
//			return 0;
//		}
//
//		int n = grid.size();
//		int m = grid[0].size();
//		vector<vector<int>> dp(2, vector<int>(m, INT_MAX));
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				dp[i % 2][j] = INT_MAX;
//
//				if (i > 0) {
//					dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j]);
//				}
//				if (j > 0) {
//					dp[i % 2][j] = min(dp[i % 2][j], dp[i % 2][j - 1]);
//				}
//
//				dp[i % 2][j] = INT_MAX == dp[i % 2][j] ? grid[i][j] : dp[i % 2][j] + grid[i][j];
//			}
//		}
//
//		return dp[(n - 1) % 2][m - 1];
//	}
//};