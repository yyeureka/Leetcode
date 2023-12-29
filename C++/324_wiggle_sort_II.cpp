#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Note:
You may assume all input has valid answer.
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Example 1:
Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:
Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].

解题思路：
以median partition
以size为6为例，将大于median的放在1、3、5，将小于median的放在0、2、4，等于的不动
*/

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		nth_element(nums.begin(), nums.begin() + n / 2, nums.end()); //类似#215 bs+partition找kth
		int mid = nums[n / 2];
		int start = 0;
		int i = 0;
		int end = n - 1;
		#define IDX(i)  (1 + 2 * i) % (n | 1)
		while (i <= end) {
			if (nums[IDX(i)] > mid) { //因为先小后打，因此这里是>
				swap(nums[IDX(i++)], nums[IDX(start++)]);
			}
			else if (nums[IDX(i)] < mid) {
				swap(nums[IDX(i)], nums[IDX(end--)]);
			}
			else i++;
		}
	}
};