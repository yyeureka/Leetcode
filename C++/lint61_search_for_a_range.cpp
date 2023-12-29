#include "head.h"

/*
Given a sorted array of n integers, find the starting and ending position of a given target value.
If the target is not found in the array, return [-1, -1].

Example 1:
Input:
[]
9
Output:
[-1,-1]
Example 2:
Input:
[5, 7, 7, 8, 8, 10]
8
Output:
[3, 4]

Challenge
O(log n) time.

解题思路：
1、第一遍找左bound，第二遍找右bound，方法：找到target不return，继续往左/右找
2、往左&右BS直到找不到为止
*/

class Solution {
public:
	vector<int> searchRange(vector<int> &A, int target) {
		if (A.empty()) return{ -1, -1 };

		vector<int> res;
		int start = 0;
		int end = A.size() - 1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] >= target) end = mid;
			else start = mid;
		}

		if (target == A[start]) res.push_back(start);
		else if (target == A[end]) res.push_back(end);
		else return{ -1, -1 };

		end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] <= target) start = mid;
			else end = mid;
		}

		if (target == A[end]) res.push_back(end);
		else res.push_back(start);

		return res;
	}
};

////不是最优解
//class Solution {
//public:
//	int search(vector<int> &A, int l, int r, int target) {
//		while (l <= r) {
//			int mid = l + (r - l) / 2;
//			if (A[mid] == target) return mid;
//			else if (A[mid] > target) r = mid - 1;
//			else l = mid + 1;
//		}
//		return -1;
//	}
//
//	vector<int> searchRange(vector<int> &A, int target) {
//		int mid = search(A, 0, A.size() - 1, target);
//		if (mid >= 0) {
//			int l = mid;
//			int r = mid;
//			while ((mid = search(A, 0, r - 1, target)) >= 0) r = mid;
//			while ((mid = search(A, l + 1, A.size() - 1, target)) >= 0) l = mid;
//			return{ r, l };
//		}
//		return{ -1, -1 };
//	}
//};