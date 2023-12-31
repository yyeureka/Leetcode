#include "head.h"

/*
Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.
Return the absolute value of difference between the sum of the two integers and the target.

Example1
Input:  nums = [-1, 2, 1, -4] and target = 4
Output: 1
Explanation:
The minimum difference is 1. (4 - (2 + 1) = 1).
Example2
Input:  nums = [-1, -1, -1, -4] and target = 4
Output: 6
Explanation:
The minimum difference is 6. (4 - (- 1 - 1) = 6).

Challenge
Do it in O(nlogn) time complexity.
*/

class Solution {
public:
	int twoSumClosest(vector<int> &nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		int diff = INT_MAX;

		sort(nums.begin(), nums.end());
		while (start < end) {
			int sum = nums[start] + nums[end];

			if (sum == target) return 0;
			else if (sum > target) {
				diff = min(diff, sum - target);
				end--;
			}
			else {
				diff = min(diff, target - sum);
				start++;
			}
		}

		return diff;
	}
};