#include <vector>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
Note: m and n will be at most 100.

Example 1:
Input:
[
[0,0,0],
[0,1,0],
[0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

解题思路：
坐标型dp
1、dp
2、滚动数组，细节非常容易写错
超贱的！中间值加完了可能int溢出！数组要开long long的
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) {
			return 0;
		}
		if (1 == obstacleGrid[0][0]) {
			return 0;
		}

		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<vector<long long>> dp(n, vector<long long>(m, 0)); //用例会int溢出
		dp[0][0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (1 == obstacleGrid[i][j]) {
					continue;
				}

				if (i > 0) {
					dp[i][j] += dp[i - 1][j];
				}
				if (j > 0) {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}

		return dp[n - 1][m - 1];
	}
};

//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		if (obstacleGrid.empty()) {
//			return 0;
//		}
//		if (1 == obstacleGrid[0][0]) { //易漏
//			return 0;
//		}
//
//		int n = obstacleGrid.size();
//		int m = obstacleGrid[0].size();
//		vector<vector<long long>> dp(2, vector<long long>(m, 0));
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (1 == obstacleGrid[i][j]) {
//					dp[i % 2][j] = 0; //极易错
//					continue;
//				}
//				if (0 == i && 0 == j) {
//					dp[0][0] = 1;
//					continue;
//				}
//
//				dp[i % 2][j] = 0; //极易错
//				if (i > 0) {
//					dp[i % 2][j] += dp[(i - 1) % 2][j];
//				}
//				if (j > 0) {
//					dp[i % 2][j] += dp[i % 2][j - 1];
//				}
//			}
//		}
//
//		return dp[(n - 1) % 2][m - 1];
//	}
//};

