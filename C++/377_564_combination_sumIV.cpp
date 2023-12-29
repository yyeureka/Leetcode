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

����˼·����ȫ����dp
���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳���㲻ͬ���

�����⣺
#39         ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
#40/lint153 ���ظ���������ѡ�ظ�����һ����ֻ����һ�Σ���ͬ����ͬ˳������ͬ���
lint135     ���ظ���������ѡ�ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
#216        ���ظ���1~9��һ����ֻ����һ�Σ���ʹ��k����
*/

class Solution {
public:
	int backPackVI(vector<int> &nums, int target) {
		if (nums.empty()) {
			return 0;
		}

		vector<int> dp(target + 1, 0); //leetcode���м�ֵ�������unsigned int
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