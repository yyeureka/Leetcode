#include "head.h"

/*
Partition an integers array into odd number first and even number second.

Example 1:
Input: [1,2,3,4]
Output: [1,3,2,4]
Example 2:
Input: [1,4,2,3,5,6]
Output: [1,3,5,4,2,6]

Challenge
Do it in-place.

Notice
The answer is not unique. All you have to do is give a vaild answer.

解题思路：类似lint31
*/

class Solution {
public:
	void partitionArray(vector<int> &nums) {
		if (nums.empty()) return;

		int i = 0;
		int j = nums.size() - 1;

		while (i <= j) {
			while (i <= j && nums[i] & 1) i++;
			while (i <= j && !(nums[j] & 1)) j--;

			if (i <= j) swap(nums[i++], nums[j--]);
		}
	}
};