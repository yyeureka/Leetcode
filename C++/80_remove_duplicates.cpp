﻿#include <vector>
#include <iostream>
using namespace std;

/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
It doesn't matter what values are set beyond the returned length.
*/


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (0 == nums.size())
		{
			return 0;
		}

		int j = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if ((nums[j] != nums[i]) || (j < 1) || (nums[j - 1] != nums[i]))
			{
				nums[++j] = nums[i];
			}
		}

		return j + 1;
	}
};

//void main()
//{
//	vector <int> nums = { 1,1,1,2,2,3 };
//	Solution s;
//	cout << (s.removeDuplicates(nums)) << endl;
//}