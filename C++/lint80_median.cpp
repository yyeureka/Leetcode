#include "head.h"

/*
Given a unsorted array with integers, find the median of it.
A median is the middle number of the array after it is sorted.
If there are even numbers in the array, return the N/2-th number after sorted.

Example 1:
Input：[4, 5, 1, 2, 3]
Output：3
Explanation:
After sorting，[1,2,3,4,5]，the middle number is 3
Example 2:
Input：[7, 9, 4, 5]
Output：5
Explanation:
After sorting，[4,5,7,9]，the second(4/2) number is 5

Challenge
O(n) time.

Notice
The size of array is not exceed 10000

解题思路：
quick select的find kth问题，类似lint461
*/

class Solution {
public:
	int median(vector<int> &nums) {
		if (nums.empty()) {
			return -1;
		}

		return findKth(nums, 0, nums.size() - 1, (nums.size() + 1) / 2);
	}

	int findKth(vector<int> &nums, int start, int end, int k) {
		if (start >= end) return nums[k - 1];

		int i = start;
		int j = end;
		int pivot = nums[(i + j) / 2];

		while (i <= j) {
			while (i <= j && nums[i] < pivot) i++;
			while (i <= j && nums[j] > pivot) j--;

			if (i <= j) swap(nums[i++], nums[j--]);
		}

		if (k - 1 <= j) findKth(nums, start, j, k);
		if (k - 1 >= i) findKth(nums, i, end, k);
		return nums[k - 1];
	}
};