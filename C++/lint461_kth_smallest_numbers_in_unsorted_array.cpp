#include "head.h"

/*
Find the kth smallest number in an unsorted integer array.

Example 1:
Input: [3, 4, 1, 2, 5], k = 3
Output: 3
Example 2:
Input: [1, 1, 1], k = 2
Output: 1

Challenge
An O(nlogn) algorithm is acceptable, if you can do it in O(n), that would be great.
*/

class Solution {
public:
	int kthSmallest(int k, vector<int> &nums) {
		if (nums.empty()) return -1;

		return quickSelect(nums, 0, nums.size() - 1, k); //k不减1
	}

	int quickSelect(vector<int> &nums, int start, int end, int k) {
		if (start >= end) return nums[k - 1]; //start或k-1都可

		int i = start;
		int j = end;
		int pivot = nums[(i + j) / 2]; //pivot要保存

		while (i <= j) {
			while (i <= j && nums[i] < pivot) i++; //先左先右无所谓
			while (i <= j && nums[j] > pivot) j--;

			if (i <= j) swap(nums[i++], nums[j--]);
		}

		if (j >= k - 1) return quickSelect(nums, start, j, k);
		if (i <= k - 1) return quickSelect(nums, i, end, k);
		return nums[k - 1]; //易错，不是k
	}
};