#include <vector>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

解题思路：
二分查找，比较mid、target、end之间的关系
*/

class Solution {
public:
	int search(vector<int> &A, int target) {
		if (A.empty()) return -1;

		int start = 0;
		int end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (target == A[mid]) return mid;
			else if (target > A[mid]) {
				if (A[mid] < A[end] == target <= A[end]) start = mid; //极易错 mid和target在同一边
				else end = mid;
			}
			else {
				if (A[mid] < A[end] == target <= A[end]) end = mid;
				else start = mid;
			}
		}

		if (target == A[start]) return start;
		if (target == A[end]) return end;
		return -1;
	}
};

//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int start = 0;
//		int end = nums.size() - 1;
//
//		while (start <= end) { //易错点
//			int mid = start + (end - start) / 2;
//
//			if (nums[mid] == target) return mid;
//			else if (nums[mid] < target) {
//				if (nums[mid] < nums[end] == target <= nums[end]) start = mid + 1; //<=极易错
//				else end = mid - 1;
//			}
//			else {
//				if (nums[mid] < nums[end] == target <= nums[end]) end = mid - 1;
//				else start = mid + 1;
//			}
//		}
//		return -1;
//	}
//};