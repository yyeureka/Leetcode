#include "head.h"

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Example 1:
Input the following triangle:
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
Output: 11
Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Example 2:
Input the following triangle:
[
[2],
[3,2],
[6,5,7],
[4,4,8,1]
]
Output: 12
Explanation: The minimum path sum from top to bottom is 12 (i.e., 2 + 2 + 7 + 1 = 12).

Notice
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

解题思路：
1、dp

3、dfs traverse——TLE
4、dfs divide conquer——TLE
*/

class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.empty()) {
			return 0;
		}

		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				int pre = INT_MAX;
				if (j > 0) {
					pre = min(pre, triangle[i - 1][j - 1]);
				}
				if (j < triangle[i - 1].size()) {
					pre = min(pre, triangle[i - 1][j]);
				}

				triangle[i][j] += pre;
			}
		}

		int minSum = INT_MAX;
		for (int i : triangle.back()) {
			minSum = min(minSum, i);
		}

		return minSum;
	}
};

////divide conquer+memoization
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>> &triangle) {
//		if (triangle.empty()) {
//			return 0;
//		}
//
//		unordered_map<int, int> memo;
//
//		return dfs(triangle, 0, 0, memo);
//	}
//
//	int dfs(vector<vector<int>> &triangle, int x, int y, unordered_map<int, int> &memo) {
//		if (x == triangle.size()) {
//			return 0;
//		}
//
//		int m = triangle.back().size();
//
//		if (memo.find(x * m + y) != memo.end()) {
//			return memo[x * m + y];
//		}
//		memo[x * m + y] = triangle[x][y] + min(dfs(triangle, x + 1, y, memo), dfs(triangle, x + 1, y + 1, memo));
//
//		return memo[x * m + y];
//	}
//};

////dfs traverse
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>> &triangle) {
//		if (triangle.empty()) {
//			return 0;
//		}
//
//		int minSum = INT_MAX;
//		dfs(triangle, 0, 0, 0, minSum);
//
//		return minSum;
//	}
//
//	void dfs(vector<vector<int>> &triangle, int x, int y, int sum, int &minSum) {
//		if (x >= triangle.size()) {
//			minSum = min(minSum, sum);
//			return;
//		}
//
//		dfs(triangle, x + 1, y, sum + triangle[x][y], minSum);
//		dfs(triangle, x + 1, y + 1, sum + triangle[x][y], minSum);
//	}
//};