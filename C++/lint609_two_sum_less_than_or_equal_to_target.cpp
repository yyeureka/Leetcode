#include "head.h"

/*
Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. Please return the number of pairs.

Example 1:
Input: nums = [2, 7, 11, 15], target = 24.
Output: 5.
Explanation:
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 24
Example 2:
Input: nums = [1], target = 1.
Output: 0.

解题思路：类似#611
*/

class Solution {
public:
	int twoSum5(vector<int> &nums, int target) {
		if (nums.empty()) return 0;

		int count = 0;
		int left = 0;
		int right = nums.size() - 1;

		sort(nums.begin(), nums.end());
		while (left < right) {
			if (nums[left] + nums[right] <= target) {
				count += right - left;
				left++;
			}
			else right--;
		}

		return count;
	}
};