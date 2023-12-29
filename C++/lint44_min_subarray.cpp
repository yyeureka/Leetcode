#include "head.h"

/*
给定一个整数数组，找到一个具有最小和的子数组。返回其最小和。
输入：[1, -1, -2, 1]
输出：-3
输入：[1, -1, -2, 1, -4]
输出：-6

解题思路：跟#53一个套路
1、prefixsum
2、greedy
*/

//prefixsum
class Solution {
public:
	/*
	* @param nums: a list of integers
	* @return: A integer indicate the sum of minimum subarray
	*/
	int minSubArray(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}

		int sum = 0;
		int prefixMax = 0; //易错
		int minSum = INT_MAX;

		for (int i : nums) {
			sum += i;
			minSum = min(minSum, sum - prefixMax);
			prefixMax = max(prefixMax, sum);
		}

		return minSum;
	}
};

////greedy
//class Solution {
//public:
//	int minSubArray(vector<int> &nums) {
//		if (nums.empty()) return 0;
//
//		int minSum = INT_MAX;
//		int sum = 0;
//		for (int i : nums) {
//			if (sum < 0) sum += i;
//			else sum = i;
//
//			minSum = min(minSum, sum);
//		}
//
//		return minSum;
//	}
//};