#include "head.h"

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
nums = [1, 2, 3]
target = 4
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.
Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

解题思路：完全背包dp
无重复数，一个数能重复使用，相同数不同顺序算不同组合

类似题：
#39         无重复数，一个数能重复使用，相同数不同顺序算相同组合
#40/lint153 有重复数，可以选重复数，一个数只能用一次，相同数不同顺序算相同组合
lint135     有重复数，不能选重复数，一个数能重复使用，相同数不同顺序算相同组合
#216        无重复数1~9，一个数只能用一次，需使用k个数
*/

class Solution {
public:
	int backPackVI(vector<int> &nums, int target) {
		if (nums.empty()) {
			return 0;
		}

		vector<int> dp(target + 1, 0); //leetcode会中间值溢出，用unsigned int
		dp[0] = 1;

		for (int i = 1; i <= target; i++) {
			for (int j : nums) {
				if (j > i) {
					continue;
				}

				dp[i] += dp[i - j];
			}
		}

		return dp[target];
	}
};