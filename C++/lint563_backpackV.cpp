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

����˼·��dp 0-1����������#562��ע�����𣺲��޸����������ظ�ȡ
dp[i][j]Ϊǰi����Ʒ����װ������j�ĸ���
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i]])
��Ϊ��ȡ��ǰ��Ʒ��ȡ��ǰ��Ʒ֮������ֵ

��[1,2,3,3,7]��targetΪ7Ϊ��
     0 1 2 3 4 5 6 7
  0: 1 0 0 0 0 0 0 0
1 1: 1 1 0 0 0 0 0 0
2 2: 1 1 1 1 0 0 0 0
3 3: 1 1 1 2 1 1 1 0
3 4: 1 1 1 3 2 2 3 1
7 5: 1 1 1 3 2 2 3 2

challenge���ռ��Ż�
1���������飬��άdp�Ϳ��Խ��
2�����齵ά��û��Ϊʲô����

challenge����ӡ���
*/

class Solution {
public:
	int backPackV(vector<int> &nums, int target) {
		if (nums.empty() || target <= 0) {
			return 0;
		}

		vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
		dp[0][0] = 1; //�ؼ�

		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j <= target; j++) { //�״����ܴ�1��ʼ
				dp[i][j] += dp[i - 1][j];

				if (j - nums[i - 1] >= 0) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[nums.size()][target];
	}
};

//��ά
//class Solution {
//public:
//	int backPackV(vector<int> &nums, int target) {
//		if (nums.empty() || target <= 0) {
//			return 0;
//		}
//
//		vector<int> dp(target + 1, 0);
//		dp[0] = 1; //�ؼ�
//
//		for (int i = 0; i < nums.size(); i++) {
//			for (int j = target; j >= nums[i]; j--) { //j��A[i]��m�����ظ�ѡͬһ����  
//				dp[j] += dp[j - nums[i]];
//			}
//		}
//
//		return dp[target];
//	}
//};