#include "head.h"

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

Example 1:
Input:1,2,3
Output:1,3,2
Example 2:
Input:3,2,1
Output:1,2,3
Example 3:
Input:1,1,5
Output:1,5,1

Challenge
The replacement must be in-place, do not allocate extra memory.

解题思路：跟#31一模一样
*/

class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		if (nums.size() <= 1) return;

		int i;
		int j;
		for (i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] >= nums[i + 1]) continue;

			for (j = nums.size() - 1; j > i; j--) {
				if (nums[j] > nums[i]) {
					swap(nums[j], nums[i]);
					break;
				}
			}
			break;
		}

		reverse(nums.begin() + i + 1, nums.end());
	}
};