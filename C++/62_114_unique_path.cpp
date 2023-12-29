#include <vector>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:
Input: m = 7, n = 3
Output: 28

解题思路：dp，时间&空间复杂度O(M*N)
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> res(m, vector<int>(n, 0));
		res[0][0] = 1;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0) {
					res[i][j] += res[i - 1][j];
				}
				if (j > 0) {
					res[i][j] += res[i][j - 1];
				}
			}
		}

		return res[m - 1][n - 1];
	}
};