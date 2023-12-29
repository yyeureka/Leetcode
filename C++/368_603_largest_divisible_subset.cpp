#include "head.h"

/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

Example 1:
Input: nums =  [1,2,3],
Output: [1,2] or [1,3]
Example 2:
Input: nums = [1,2,4,8],
Output: [1,2,4,8]

Notice
If there are multiple solutions, return any subset is fine.

解题思路：#300 LIS衍生题
*/

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		if (nums.empty()) {
			return{};
		}

		int n = nums.size();
		int maxLen = INT_MIN;
		int maxIdx = -1;
		vector<int> dp(n, 1);
		vector<int> preIdx(n, -1);

		sort(nums.begin(), nums.end()); //易错

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (0 == nums[i] % nums[j] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					preIdx[i] = j;
				}
			}

			if (dp[i] > maxLen) {
				maxLen = dp[i];
				maxIdx = i;
			}
		}

		vector<int> subset;

		while (-1 != maxIdx) {
			subset.push_back(nums[maxIdx]);
			maxIdx = preIdx[maxIdx];
		}

		return subset;
	}
};