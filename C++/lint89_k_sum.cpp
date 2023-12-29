#include "head.h"

/*
Given n distinct positive integers, integer k (k <= n) and a number target.
Find k numbers where sum is target. Calculate how many solutions there are?

Example 1
Input:
List = [1,2,3,4]
k = 2
target = 5
Output: 2
Explanation: 1 + 4 = 2 + 3 = 5
Example 2
Input:
List = [1,2,3,4,5]
k = 3
target = 6
Output: 1
Explanation: There is only one method. 1 + 2 + 3 = 6

解题思路：
1、有限个数的0-1背包，lint125变种
   dp[i][j][l]为前i个数取j个和为l的个数
2、组合dfs会TLE
*/

class Solution {
public:
	int backpack(vector<int> &A, int k, int target) {
		if (A.empty() || target <= 0 || k <= 0) {
			return 0;
		}

		vector<vector<vector<int>>> dp(A.size() + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
		dp[0][0][0] = 1;

		for (int i = 1; i <= A.size(); i++) {
			dp[i][0][0] = 1; //易错！

			for (int j = 1; j <= k && j <= i; j++) { //加上j<=i大大增加效率
				for (int l = 1; l <= target; l++) {
					dp[i][j][l] = dp[i - 1][j][l];

					if (l - A[i - 1] >= 0) {
						dp[i][j][l] += dp[i - 1][j - 1][l - A[i - 1]];
					}
				}
			}
		}

		return dp[A.size()][k][target];
	}
};

//滚动数组
//class Solution {
//public:
//	int kSum(vector<int> &A, int k, int target) {
//		if (A.empty() || target <= 0 || k <= 0) {
//			return 0;
//		}
//
//		vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
//		dp[0][0][0] = 1;
//
//		for (int i = 1; i <= A.size(); i++) {
//			dp[i % 2][0][0] = 1;
//
//			for (int j = 1; j <= k && j <= i; j++) {
//				for (int l = 1; l <= target; l++) {
//					dp[i % 2][j][l] = dp[(i - 1) % 2][j][l];
//
//					if (l - A[i - 1] >= 0) {
//						dp[i % 2][j][l] += dp[(i - 1) % 2][j - 1][l - A[i - 1]];
//					}
//				}
//			}
//		}
//
//		return dp[A.size() % 2][k][target];
//	}
//};

//dfs TLE
//class Solution {
//public:
//	int kSum(vector<int> &A, int k, int target) {
//		int result = 0;
//
//		helper(A, 0, k, target, result);
//
//		return result;
//	}
//
//	void helper(vector<int> &A, int index, int size, int target, int &result) {
//		if (0 == size) {
//			if (0 == target) {
//				result++;
//			}
//			return;
//		}
//
//		for (int i = index; i < A.size(); i++) {
//			if (target < A[i]) continue;
//
//			helper(A, i + 1, size - 1, target - A[i], result);
//		}
//	}
//};