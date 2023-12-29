#include "head.h"

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

解题思路：prefixSum方法
易错点：可能出现重复的sum
*/

class Solution {
public:
	int subarraySumEqualsK(vector<int> &nums, int k) {
		if (nums.empty()) {
			return 0;
		}

		int count = 0;
		int sum = 0;
		unordered_map<int, int> prefixSum;
		prefixSum[0] = 1; //易错

		for (int i : nums) {
			sum += i;

			if (prefixSum.find(sum - k) != prefixSum.end()) {
				count += prefixSum[sum - k];
			}

			prefixSum[sum]++;
		}

		return count;
	}
};