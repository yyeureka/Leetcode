#include "head.h"

/*
Given a 2D matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Example1
Input:
[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]
sumRegion(2, 1, 4, 3)
sumRegion(1, 1, 2, 2)
sumRegion(1, 2, 2, 4)
Output:
8
11
12
Explanation:
Given matrix =
[
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) = 2 + 0 + 1 + 1 + 0 + 1 + 0 + 3 + 0 = 8
sumRegion(1, 1, 2, 2) = 6 + 3 + 2 + 0 = 11
sumRegion(1, 2, 2, 4) = 3 + 2 + 1 + 0 + 1 + 5 = 12
Example2
Input:
[[3,0],[5,6]]
sumRegion(0, 0, 0, 1)
sumRegion(0, 0, 1, 1)
Output:
3
14
Explanation:
Given matrix =
[
[3, 0],
[5, 6]
]
sumRegion(0, 0, 0, 1) = 3 + 0 = 3
sumRegion(0, 0, 1, 1) = 3 + 0 + 5 + 6 = 14

Notice
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

解题思路：
1、dp
2、二维prefix sum，先根据col压缩一维
*/

//dp
class NumMatrix {
private:
	vector<vector<int>> dp;
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}

		int n = matrix.size();
		int m = matrix[0].size();

		dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}
};

//prefix sum
//class NumMatrix {
//private:
//	vector<vector<int>> prefixColSum;
//public:
//	NumMatrix(vector<vector<int>> matrix) {
//		if (matrix.empty() || matrix[0].empty()) {
//			return;
//		}
//
//		int n = matrix.size();
//		int m = matrix[0].size();
//
//		prefixColSum = vector<vector<int>>(n + 1, vector<int>(m, 0));
//
//		for (int i = 0; i < m; i++) {
//			for (int j = 1; j <= n; j++) {
//				prefixColSum[j][i] = matrix[j - 1][i] + prefixColSum[j - 1][i];
//			}
//		}
//	}
//
//	int sumRegion(int row1, int col1, int row2, int col2) {
//		int results = 0;
//
//		for (int i = col1; i <= col2; i++) {
//			results += prefixColSum[row2 + 1][i] - prefixColSum[row1][i];
//		}
//
//		return results;
//	}
//};