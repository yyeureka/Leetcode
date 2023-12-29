#include "head.h"

/*
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Example 1:
Input: nums = [1,1,2,45,46,46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47
Example 2:
Input: nums = [1,1], target = 2
Output: 1
Explanation:
1 + 1 = 2

����˼·��sortȥ�غ�����#167
*/

class Solution {
public:
	int twoSum6(vector<int> &nums, int target) {
		if (nums.empty()) return 0;

		int count = 0;
		int start = 0;
		int end = nums.size() - 1;

		sort(nums.begin(), nums.end()); //�ؼ���

		while (start < end) {
			int sum = nums[start] + nums[end];

			if (target == sum) {
				count++;
				start++;
				end--;

				while (start < end && nums[start] == nums[start - 1]) start++; //ȥ��
				while (start < end && nums[end] == nums[end + 1]) end--;
			}
			else if (sum < target) start++;
			else end--;
		}

		return count;
	}
};