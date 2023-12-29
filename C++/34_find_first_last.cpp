#include <vector>
using namespace std;

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

解题思路：
二分查找 找到了一个后，while往左边找first，while往右边找last
*/

int search(vector<int>& nums, int start, int end, int target)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int n = nums.size();
		int idx = search(nums, 0, n - 1, target);
		if (-1 == idx) return res;

		res[0] = idx;
		int start = idx;
		while (start > 0)
		{
			start = search(nums, 0, start - 1, target);
			if (-1 == start) break;
			res[0] = start;
		}

		res[1] = idx;
		int end = idx;
		while (end < n - 1)
		{
			end = search(nums, end + 1, n - 1, target);
			if (-1 == end) break;
			res[1] = end;
		}

		return res;
	}
};