#include "head.h"

/*
Given n items with size nums[i] which an integer array and all positive numbers. An integer target denotes the size of a backpack. Find the number of possible fill the backpack.
Each item may only be used once

Example
Given candidate items [1,2,3,3,7] and target 7,
A solution set is:
[7]
[1, 3, 3]
return 2

解题思路：dp 0-1背包，类似#562，注意区别：不限个数，不能重复取
dp[i][j]为前i个物品正好装满容量j的个数
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i]])
即为不取当前物品、取当前物品之间的最大值

以[1,2,3,3,7]，target为7为例
     0 1 2 3 4 5 6 7
  0: 1 0 0 0 0 0 0 0
1 1: 1 1 0 0 0 0 0 0
2 2: 1 1 1 1 0 0 0 0
3 3: 1 1 1 2 1 1 1 0
3 4: 1 1 1 3 2 2 3 1
7 5: 1 1 1 3 2 2 3 2

challenge：空间优化
1、滚动数组，二维dp就可以解决
2、数组降维，没懂为什么？？

challenge：打印结果
*/

class Solution {
public:
	int backPackV(vector<int> &nums, int target) {
		if (nums.empty() || target <= 0) {
			return 0;
		}

		vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
		dp[0][0] = 1; //关键

		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j <= target; j++) { //易错，不能从1开始
				dp[i][j] += dp[i - 1][j];

				if (j - nums[i - 1] >= 0) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[nums.size()][target];
	}
};

//降维
//class Solution {
//public:
//	int backPackV(vector<int> &nums, int target) {
//		if (nums.empty() || target <= 0) {
//			return 0;
//		}
//
//		vector<int> dp(target + 1, 0);
//		dp[0] = 1; //关键
//
//		for (int i = 0; i < nums.size(); i++) {
//			for (int j = target; j >= nums[i]; j--) { //j从A[i]到m即可重复选同一个数  
//				dp[j] += dp[j - nums[i]];
//			}
//		}
//
//		return dp[target];
//	}
//};