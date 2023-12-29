#include "head.h"

/*
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.

Example1:
Input: [1, 3, 3, 4, 5] and target = 3,
Output: 2.
Example2:
Input: [2, 2, 3, 4, 6] and target = 4,
Output: 1.
Example3:
Input: [1, 2, 3, 4, 5] and target = 6,
Output: 0.

Challenge
Time complexity in O(logn)

解题思路：类似lint61
*/

class Solution {
public:
	int totalOccurrence(vector<int> &A, int target) {
		if (A.empty()) return 0;

		int start = 0;
		int end = A.size() - 1;
		int left = -1;
		int right = -1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] >= target) end = mid;
			else start = mid;
		}

		if (target == A[start]) left = start;
		else if (target == A[end]) left = end;
		if (left < 0) return 0;

		end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] <= target) start = mid;
			else end = mid;
		}

		if (target == A[end]) right = end;
		else right = start;

		return right - left + 1;
	}
};