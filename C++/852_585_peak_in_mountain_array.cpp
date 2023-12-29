#include "head.h"

/*
Let's call an array A a mountain if the following properties hold:
A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
Note:
3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.

Example 1:
Input: [0,1,0]
Output: 1
Example 2:
Input: [0,2,1,0]
Output: 1

解题思路：类似#162
*/

class Solution {
public:
	int mountainSequence(vector<int> &nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (nums[mid] < nums[mid + 1]) start = mid;
			else end = mid;
		}

		return max(nums[start], nums[end]);
	}
};

//class Solution {
//public:
//	int peakIndexInMountainArray(vector<int>& A) {
//		int start = 0;
//		int end = A.size() - 1;
//		while (start < end) {
//			int mid = start + (end - start) / 2;
//			if (A[mid] > A[mid + 1]) end = mid;
//			else start = mid + 1;
//		}
//		return start;
//	}
//};