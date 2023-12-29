#include "head.h"

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2]
Output: 1
Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0

解题思路：binary search
比较mid和end
易错：可能在位置0或末尾rotate，相当于没有折！！
*/

class Solution {
public:
	int findMin(vector<int> &nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (nums[start] < nums[end]) return nums[start];

			if (nums[mid] < nums[end]) end = mid;
			else start = mid;
		}

		return min(nums[start], nums[end]);
	}
};

//class Solution {
//public:
//	int findMin(vector<int> &nums) {
//		int findMin(vector<int> &nums) {
//			if (nums.empty()) return -1;
//
//			int start = 0;
//			int end = nums.size() - 1;
//
//			while (start < end) {
//				if (nums[start] < nums[end]) break;
//
//				int mid = start + (end - start) / 2;
//
//				if (nums[mid] < nums[end]) end = mid;
//				else start = mid + 1;
//			}
//
//			return nums[start];
//		}
//	}
//};