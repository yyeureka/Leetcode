#include <vector>
using namespace std;

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example 1:
Input: nums = [0, 1, 0, 3, 12],
Output: [1, 3, 12, 0, 0].
Example 2:
Input: nums = [0, 0, 0, 3, 1],
Output: [3, 1, 0, 0, 0].

Notice
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

解题思路：
1、同向双指针
2、如果题目不要求保持原来的顺序，可以用partition，能最小化操作
*/

class Solution {
public:
	void moveZeroes(vector<int> &nums) {
		if (nums.empty()) return;

		int i = 0;
		for (int j : nums) {
			if (0 == j) continue;

			nums[i++] = j;
		}
		for (i; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};

//class Solution {
//public:
//	void moveZeroes(vector<int> &nums) {
//		if (nums.empty()) return;
//
//		int i = 0;
//		for (int j = 0; j < nums.size(); j++) {
//			if (0 == nums[j]) continue;
//
//			swap(nums[i++], nums[j]);
//		}
//	}
//};