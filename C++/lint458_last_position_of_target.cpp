#include "head.h"

/*
Find the last position of a target number in a sorted array. Return -1 if target does not exist.

Example 1:
Input: nums = [1,2,2,4,5,5], target = 2
Output: 2
Example 2:
Input: nums = [1,2,2,4,5,5], target = 6
Output: -1
*/

class Solution {
public:
	int lastPosition(vector<int> &nums, int target) {
		if (nums.empty()) return -1;

		int start = 0;
		int end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (target >= nums[mid]) start = mid;
			else end = mid;
		}

		if (target == nums[end]) return end;
		if (target == nums[start]) return start;
		return -1;
	}
};

//class Solution {
//public:
//	int lastPosition(vector<int> &nums, int target) {
//		int l = 0;
//		int r = nums.size() - 1;
//		int res = -1;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (target == nums[mid]) res = mid;
//			if (target >= nums[mid]) l = mid + 1;
//			else r = mid - 1;
//		}
//		return res;
//	}
//};

//class Solution {
//public:
//	int search(vector<int> &nums, int target, int l, int r) {
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (target == nums[mid]) return mid;
//			else if (target > nums[mid]) l = mid + 1;
//			else r = mid - 1;
//		}
//		return -1;
//	}
//
//	int lastPosition(vector<int> &nums, int target) {
//		int idx = search(nums, target, 0, nums.size() - 1);
//		if (idx >= 0) {
//			int l = idx;
//			while ((idx = search(nums, target, l + 1, nums.size() - 1)) >= 0) l = idx;
//			return l;
//		}
//		return -1;
//	}
//};