#include "head.h"

/*
Given a knight in a chessboard n * m (a binary matrix with 0 as empty and 1 as barrier). the knight initialze position is (0, 0) and he wants to reach position (n - 1, m - 1), Knight can only be from left to right. Find the shortest path to the destination position, return the length of the route. Return -1 if knight can not reached.

Example 1:
Input:
[[0,0,0,0],[0,0,0,0],[0,0,0,0]]
Output:
3
Explanation:
[0,0]->[2,1]->[0,2]->[2,3]
Example 2:
Input:
[[0,1,0],[0,0,1],[0,0,0]]
Output:
-1
Clarification
If the knight is at (x, y), he can get to the following positions in one step:
(x + 1, y + 2)
(x - 1, y + 2)
(x + 2, y + 1)
(x - 2, y + 1)

解题思路：
1、BFS
2、dp
3、bidirectional BFS
*/

class Solution {
public:
	int shortestPath2(vector<vector<bool>> &grid) {
		if (grid.empty() || grid[0].empty() || grid[0][0]) {
			return -1;
		}

		int n = grid.size();
		int m = grid[0].size();
		vector<int> deltaX = { 1,-1,2,-2 };
		vector<int> deltaY = { 2,2,1,1 };
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		int len = 0;

		while (!q.empty()) {
			int size = q.size();

			for (int i = 0; i < size; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (x == n - 1 && y == m - 1) {
					return len;
				}

				for (int j = 0; j < 4; j++) {
					int nextX = x + deltaX[j];
					int nextY = y + deltaY[j];

					if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || 1 == grid[nextX][nextY]) {
						continue;
					}

					grid[nextX][nextY] = 1;
					q.push({ nextX, nextY });
				}
			}

			len++;
		}

		return -1;
	}
};

//dp
//class Solution {
//public:
//	int shortestPath2(vector<vector<bool>> &grid) {
//		if (grid.empty() || grid[0].empty() || grid[0][0]) {
//			return -1;
//		}
//
//		int n = grid.size();
//		int m = grid[0].size();
//		vector<int> deltaX = { -1,1,-2,2 };
//		vector<int> deltaY = { -2,-2,-1,-1 };
//		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
//		dp[0][0] = 0;
//
//		for (int j = 1; j < m; j++) { //易错，y=0不用计算
//			for (int i = 0; i < n; i++) {
//				if (1 == grid[i][j]) {
//					continue;
//				}
//
//				for (int k = 0; k < 4; k++) {
//					int x = i + deltaX[k];
//					int y = j + deltaY[k];
//
//					if (x < 0 || x >= n || y < 0 || y >= m || INT_MAX == dp[x][y]) {
//						continue;
//					}
//
//					dp[i][j] = min(dp[i][j], dp[x][y] + 1);
//				}
//			}
//		}
//
//		if (INT_MAX == dp[n - 1][m - 1]) {
//			return -1;
//		}
//		return dp[n - 1][m - 1];
//	}
//};

//dp滚动数组
//class Solution {
//public:
//	int shortestPath2(vector<vector<bool>> &grid) {
//		if (grid.empty() || grid[0].empty() || grid[0][0]) {
//			return -1;
//		}
//
//		int n = grid.size();
//		int m = grid[0].size();
//		vector<int> deltaX = { -1,1,-2,2 };
//		vector<int> deltaY = { -2,-2,-1,-1 };
//		vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
//		dp[0][0] = 0;
//
//		for (int j = 1; j < m; j++) {
//			for (int i = 0; i < n; i++) {
//				dp[i][j % 3] = INT_MAX; //极易错，这里不更新下面的continue会出错
//
//				if (1 == grid[i][j]) {
//					continue;
//				}
//
//				for (int k = 0; k < 4; k++) {
//					int x = i + deltaX[k];
//					int y = j + deltaY[k];
//
//					if (x < 0 || x >= n || y < 0 || y >= m || INT_MAX == dp[x][y % 3]) {
//						continue;
//					}
//
//					dp[i][j % 3] = min(dp[i][j % 3], dp[x][y % 3] + 1);
//				}
//			}
//		}
//
//		if (INT_MAX == dp[n - 1][(m - 1) % 3]) {
//			return -1;
//		}
//		return dp[n - 1][(m - 1) % 3];
//	}
//};
