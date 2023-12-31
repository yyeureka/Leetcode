#include "head.h"

/*
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Example 1
Input:  [-3, 1, 2, -3, 4]
Output: [0, 2] or [1, 3].
Explanation: return anyone that the sum is 0.
Example 2:
Input:  [-3, 1, -4, 2, -3, 4]
Output: [1,5]
Notice
There is at least one subarray that it's sum equals to zero.

解题思路：prefixSum方法
*/

class Solution {
public:
	vector<int> subarraySum(vector<int> &nums) {
		if (nums.empty()) {
			return{};
		}

		int sum = 0;
		unordered_map<int, int> prefixSum;
		prefixSum[0] = -1; //易错

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (prefixSum.find(sum) != prefixSum.end()) {
				return{ prefixSum[sum] + 1, i };
			}

			prefixSum[sum] = i;
		}

		return{};
	}
};