#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

解题思路：
dp，每个状态保存max和min，下一个状态如果>0，max和min分别考虑上一个的max和min，如果<0，max和min分别考虑上一个的min和max

dp可以开一个vector
follow up：
空间优化 只要一个max和min就可以代替vector了！！！
*/

class Solution {
public:
	int maxProduct(vector<int> &nums) {
		if (nums.empty()) return 0; //不能漏

		int n = nums.size();
		int maxP = nums[0];
		int minP = maxP;
		int result = maxP;

		for (int i = 1; i < n; i++) {
			if (nums[i] < 0) {
				swap(maxP, minP);
			}

			maxP = max(nums[i], nums[i] * maxP);
			minP = min(nums[i], nums[i] * minP);
			result = max(result, maxP);
		}

		return result;
	}
};

//空间需优化版本
//class Solution {
//public:
//	int maxProduct(vector<int> &nums) {
//		if (nums.empty()) return 0;
//
//		int result = INT_MIN;
//		vector<vector<int>> dp(n, vector<int>(2));
//
//		for (int i = 0; i < n; i++) {
//			dp[i][0] = nums[i];
//			dp[i][1] = nums[i];
//
//			if (i > 0) {
//				if (nums[i] > 0) {
//					dp[i][0] = max(dp[i][0], nums[i] * dp[i - 1][0]);
//					dp[i][1] = min(dp[i][1], nums[i] * dp[i - 1][1]);
//				}
//				else {
//					dp[i][0] = max(dp[i][0], nums[i] * dp[i - 1][1]);
//					dp[i][1] = min(dp[i][1], nums[i] * dp[i - 1][0]);
//				}
//			}
//
//			result = max(result, dp[i][0]);
//		}
//
//		return result;
//	}
//};

