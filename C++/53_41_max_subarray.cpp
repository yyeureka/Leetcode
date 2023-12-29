#include "head.h"

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

解题思路：
1、prefix sum：
prefixSum[i] = A[0]+...A[i-1]
sum(i~j) = prefixSum[j+1]-prefixSum[i]
对于每一个j的maxSum，找到之前最小的prefixSum[i]
2、greedy
*/

class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}

		int sum = 0;
		int minPrefix = 0;   //易错 prefixsum从0开始
		int maxSum = INT_MIN;

		for (int i : nums) {
			sum += i;
			maxSum = max(maxSum, sum - minPrefix); //易错 求max和求min的顺序不能颠倒！
			minPrefix = min(minPrefix, sum);
		}

		return maxSum;
	}
};

////greedy
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int maxSum = INT_MIN;
//		int sum = INT_MIN;
//
//		for (int i : nums) {
//			if (sum > 0) sum += i;
//			else sum = i;
//
//			maxSum = max(maxSum, sum);
//		}
//
//		return maxSum;
//	}
//};