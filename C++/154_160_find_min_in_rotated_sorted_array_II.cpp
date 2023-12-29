#include "head.h"

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.
Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?

Example 1:
Input: [1,3,5]
Output: 1
Example 2:
Input: [2,2,2,0,1]
Output: 0

解题思路：
跟#153没有duplicate的非常类似，当mid和end相等的时候会没办法判断，需要特殊处理
不能保证O(logn)，O(n)的复杂度，以一堆0里面有个-1为例，基本需要把每一个都找过
*/

class Solution {
public:
	int findMin(vector<int> &nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (nums[start] < nums[end]) return nums[start];

			if (nums[mid] == nums[end]) start++; //比没有duplicate多了这一句，start检查过不是min，而end没有，因此不能end--
			else if (nums[mid] < nums[end]) end = mid;
			else start = mid;
		}

		return min(nums[start], nums[end]);
	}
};

//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		int start = 0;
//		int end = nums.size() - 1;
//
//		while (start < end) {
//			if (nums[start] < nums[end]) break;
//
//			int mid = start + (end - start) / 2;
//
//			if (nums[mid] == nums[end]) start++; //比没有duplicate多了这一句，start检查过不是min，而end没有，因此不能end--
//			else if (nums[mid] > nums[end]) start = mid + 1;
//			else end = mid;
//		}
//		return nums[start];
//	}
//};