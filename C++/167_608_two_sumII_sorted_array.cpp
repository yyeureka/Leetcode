#include "head.h"

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Example 1:
Input: nums = [2, 7, 11, 15], target = 9
Output: [1, 2]
Example 2:
Input: nums = [2,3], target = 5
Output: [1, 2]

Notice
You may assume that each input would have exactly one solution.
*/

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		if (nums.empty()) return{};

		int start = 0;
		int end = nums.size() - 1;

		while (start < end) {
			int sum = nums[start] + nums[end];

			if (target == sum) return{ start + 1, end + 1 };
			else if (target > sum) start++;
			else end--;
		}

		return{};
	}
};