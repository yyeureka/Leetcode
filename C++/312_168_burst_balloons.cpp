#include "head.h"

/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input：[4, 1, 5, 10]
Output：270
Explanation：
nums = [4, 1, 5, 10] burst 1, get coins 4 * 1 * 5 = 20
nums = [4, 5, 10]   burst 5, get coins 4 * 5 * 10 = 200
nums = [4, 10]    burst 4, get coins 1 * 4 * 10 = 40
nums = [10]    burst 10, get coins 1 * 10 * 1 = 10
Total coins 20 + 200 + 40 + 10 = 270
Example 2:
Input：[3,1,5]
Output：35
Explanation：
nums = [3, 1, 5] burst 1, get coins 3 * 1 * 5 = 15
nums = [3, 5] burst 3, get coins 1 * 3 * 5 = 15
nums = [5] burst 5, get coins 1 * 5 * 1 = 5
Total coins 15 + 15 + 5  = 35

Notice
You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

解题思路：区间型dp
dp[i][j]为炸掉i、j之间（不包括i、j）的所有气球获得的max coin
dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j])，i < k < j
将nums左右各插入1，返回dp[0][size-1]
*/

class Solution {
public:
	int maxCoins(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}

		nums.insert(nums.begin(), 1);
		nums.push_back(1);

		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 2; j < n; j++) {
				for (int k = i + 1; k < j; k++) {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};