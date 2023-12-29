#include "head.h"

/*
Given an integer array nums[] which contains n unique positive numbers, num[i] indicate the size of ith item. An integer target denotes the size of backpack. Find the number of ways to fill the backpack.
Each item may be chosen unlimited number of times

Example1
Input: nums = [2,3,6,7] and target = 7
Output: 2
Explanation:
Solution sets are:
[7]
[2, 2, 3]
Example2
Input: nums = [2,3,4,5] and target = 7
Output: 3
Explanation:
Solution sets are:
[2, 5]
[3, 4]
[2, 2, 3]

����˼·��dp��ȫ����������lint563��ע�����𣺲��޸����������ظ�ȡ
*/

class Solution {
public:
	int backPackIV(vector<int> &nums, int target) {
		if (nums.empty() || target <= 0) {
			return 0;
		}

		vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
		dp[0][0] = 1; //�ؼ�

		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j <= target; j++) { //�״����ܴ�1��ʼ
				int k = 0;
				while (j - nums[i - 1] * k >= 0) { //��0-1��������
					dp[i][j] += dp[i - 1][j - k * nums[i - 1]];
					k++;
				}
			}
		}

		return dp[nums.size()][target];
	}
};

//��ά
//class Solution {
//public:
//	int backPackIV(vector<int> &nums, int target) {
//		if (nums.empty() || target <= 0) {
//			return 0;
//		}
//
//		vector<int> dp(target + 1, 0);
//		dp[0] = 1;
//
//		for (int i = 0; i < nums.size(); i++) {
//			for (int j = nums[i]; j <= target; j++) { //��0-1��������
//				dp[j] += dp[j - nums[i]];
//			}
//		}
//
//		return dp[target];
//	}
//};