#include <vector>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.
Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

解题思路：
跟#33没有duplicate的非常类似，当mid和end相等的时候会没办法判断，需要特殊处理
不能保证O(logn)，O(n)的复杂度，以一堆0里面有个-1为例，基本需要把每一个都找过
*/

class Solution {
public:
	bool search(vector<int> &A, int target) {
		if (A.empty()) return false;

		int start = 0;
		int end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (target == A[mid]) return true;
			else if (A[mid] == A[end]) end--;
			else if (target > A[mid]) {
				if (A[mid] < A[end] == target <= A[end]) start = mid; //极易错 mid和target在同一边
				else end = mid;
			}
			else {
				if (A[mid] < A[end] == target <= A[end]) end = mid;
				else start = mid;
			}
		}

		if (target == A[start]) return true;
		if (target == A[end]) return true;
		return false;
	}
};

//class Solution {
//public:
//	bool search(vector<int>& nums, int target) {
//		int start = 0;
//		int end = nums.size() - 1;
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			if (target == nums[mid]) return true;
//			else if (nums[end] == nums[mid]) end--; //比没有duplicate多了这一句，end检查过不是target，start没有，因此不能start++
//			else if (target > nums[mid]) {
//				if (nums[mid] < nums[end] == target <= nums[end]) start = mid + 1;
//				else end = mid - 1;
//			}
//			else {
//				if (nums[mid] < nums[end] == target <= nums[end]) end = mid - 1;
//				else start = mid + 1;
//			}
//		}
//		return false;
//	}
//};