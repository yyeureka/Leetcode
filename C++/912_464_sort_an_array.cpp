#include "head.h"

/*
Given an array of integers nums, sort the array in ascending order.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

Constraints:
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

解题思路：
quicksort，时间复杂度平均O(nlogn)，最差O(n^2), 空间复杂度O(1)，不是稳定排序
mergesort，时间复杂度O(nlogn)，空间复杂度O(n)，会TLE
*/

//quick sort
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		if (nums.empty()) return{};

		quickSort(nums, 0, nums.size() - 1);

		return nums;
	}

	void quickSort(vector<int>& nums, int start, int end) {
		if (start >= end) return;

		int i = start;
		int j = end;
		int pivot = nums[(start + end) / 2];

		while (i <= j) {
			while (i <= j && nums[i] < pivot) i++;
			while (i <= j && nums[j] > pivot) j--;

			if (i <= j) swap(nums[i++], nums[j--]);
		}

		quickSort(nums, start, j);
		quickSort(nums, i, end);
	}
};

//merge sort
//class Solution {
//public:
//	void sortIntegers2(vector<int> &A) {
//		if (A.empty()) return;
//
//		mergeSort(A, 0, A.size() - 1);
//	}
//
//	void mergeSort(vector<int> &A, int start, int end) {
//		if (start >= end) return;
//
//		int mid = (start + end) / 2;
//		mergeSort(A, start, mid);
//		mergeSort(A, mid + 1, end);
//
//		vector<int> tmp(A.size());
//		int left = start;
//		int right = mid + 1;
//
//		for (int i = start; i <= end; i++) {
//			if (left > mid) tmp[i] = A[right++];
//			else if (right > end) tmp[i] = A[left++];
//			else if (A[left] < A[right]) tmp[i] = A[left++];
//			else tmp[i] = A[right++];
//		}
//
//		for (int i = start; i <= end; i++) {
//			A[i] = tmp[i];
//		}
//	}
//};