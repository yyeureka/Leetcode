#include <vector>
using namespace std;

/*
Given an unsorted array nums, reorder it in-place such that
nums[0] <= nums[1] >= nums[2] <= nums[3]....
Please complete the problem in-place.

Example 1:
Input: [3, 5, 2, 1, 6, 4]
Output: [1, 6, 2, 5, 3, 4]
Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also ok.
Example 2:
Input: [1, 2, 3, 4]
Output: [2, 1, 4, 3]

解题思路：
1、从第二个开始，不满足要求的直接交换
2、quick sort，然后从第二个开始两两交换
*/

class Solution {
public:
	void wiggleSort(vector<int> &nums) {
		for (int i = 1; i < nums.size(); i++) {
			if (i & 1) {
				if (nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
			}
			else {
				if (nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
			}
		}
	}
};

//class Solution {
//public:
//	void quick_sort(vector<int> &nums, int left, int right) {
//		if (left >= right) return;
//		int i = left;
//		int j = right;
//		while (i < j) {
//			while (i < j && nums[j] >= nums[left]) j--;
//			while (i < j && nums[i] <= nums[left]) i++;
//			if (i != j) swap(nums[i], nums[j]);
//		}
//		swap(nums[i], nums[left]);
//		quick_sort(nums, left, i - 1);
//		quick_sort(nums, i + 1, right);
//	}
//
//	void wiggleSort(vector<int> &nums) {
//		quick_sort(nums, 0, nums.size() - 1);
//		int i = 1;
//		while (i < nums.size() && (i + 1) < nums.size()) {
//			swap(nums[i], nums[i + 1]);
//			i += 2;
//		}
//	}
//};