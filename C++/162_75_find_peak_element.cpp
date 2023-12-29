#include <vector>
using namespace std;

/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
Note:
Your solution should be in logarithmic complexity.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
or index number 5 where the peak element is 6.

解题思路：
1、binary search
2、brute：从1开始，如果当前小于前一个元素，返回前一个元素，如果没找到，返回n-1——会TLE
*/

class Solution {
public:
	int findPeak(vector<int> &A) {
		int start = 0;
		int end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (A[mid] < A[mid + 1]) start = mid;
			else end = mid;
		}

		if (A[start] > A[end]) return start;
		else return end;
	}
};

//class Solution {
//public:
//	int findPeakElement(vector<int>& nums) {
//		int start = 0;
//		int end = nums.size() - 1;
//		while (start < end) {
//			int mid = start + (end - start) / 2;
//			if (nums[mid] < nums[mid + 1]) start = mid + 1; //mid一定<end，所以mid+1不会越界
//			else end = mid;
//		}
//		return start;
//	}
//};

//可能TLE
//class Solution {
//public:
//	int findPeakElement(vector<int>& nums) {
//		for (int i = 1; i < nums.size(); i++) {
//			if (nums[i] < nums[i - 1]) return i - 1;
//		}
//		return nums.size() - 1;
//	}
//};