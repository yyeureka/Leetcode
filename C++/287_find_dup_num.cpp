#include <vector>
#include <iostream>
using namespace std;

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Example 1:
Input: [1,3,4,2,2]
Output: 2
Example 2:
Input: [3,1,3,4,2]
Output: 3

解题思路：
只有一个数字会重复 但重复的数字可能重复好几次！！坑爹
1、类似ex41
2、sort
*/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] == i + 1) i++;
			else {
				if (nums[nums[i] - 1] == nums[i]) return nums[i];
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		return 0;

		//sort(nums.begin(), nums.end());
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	if ((i > 0) && (nums[i] == nums[i - 1]))
		//	{
		//		return nums[i];
		//	}
		//}
		//return 0;
	}
};