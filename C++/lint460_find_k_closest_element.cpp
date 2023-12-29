#include "head.h"

/*
Given target, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

Example 1:
Input: A = [1, 2, 3], target = 2, k = 3
Output: [2, 1, 3]
Example 2:
Input: A = [1, 4, 6, 8], target = 3, k = 3
Output: [4, 1, 6]

Challenge
O(logn + k) time

Notice
The value k is a non-negative integer and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4​​
Absolute value of elements in the array will not exceed 10^4​​

解题思路：
先bs找到里target最近的两个值，然后背向双指针依次将其他的加进res
*/

class Solution {
public:
	bool pickLeft(vector<int> &A, int target, int left, int right) {
		if (left < 0) return false;
		if (right >= A.size()) return true;

		if (target - A[left] <= A[right] - target) return true;
		return false;
	}

	vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
		int size = A.size();
		if (!size || size < k) return{};

		int start = 0;
		int end = size - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] <= target) start = mid; //如果==target要break的话，start和end都要更新
			else end = mid;
		}

		vector<int> res;
		for (int i = 0; i < k; i++) {
			if (pickLeft(A, target, start, end)) {
				res.push_back(A[start]);
				start--;
			}
			else {
				res.push_back(A[end]);
				end++;
			}
		}

		return res;
	}
};