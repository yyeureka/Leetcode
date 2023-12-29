#include "head.h"
using namespace std;

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

解题思路：
1、two pointer，r指针为主指针，l指针为浮指针，nums中有负数的话是不能这么用的
2、prefix sum会TLE
*/

//two pointer
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int minLen = INT_MAX;
		int sum = 0;
		int left = 0;
		int right = 0;

		while (right < nums.size()) {
			sum += nums[right++]; //不需要if sum<s

			while (left <= right && sum >= s) {
				minLen = min(minLen, right - left);
				sum -= nums[left++];
			}
		}

		return INT_MAX == minLen ? -1 : minLen; //这里容易忘
	}
};

////prefix sum
//class Solution {
//public:
//	int minSubArrayLen(int s, vector<int>& nums) {
//		int size = nums.size();
//		if (!size) return 0;
//
//		int minSize = INT_MAX;
//		int sum = 0;
//		unordered_map<int, int> m; //sum:index
//		m[0] = -1;
//		for (int i = 0; i < size; i++) {
//			sum += nums[i];
//			for (auto j : m) {
//				if (sum - j.first >= s) minSize = min(minSize, i - j.second);
//			}
//
//			m[sum] = i;
//		}
//
//		return INT_MAX == minSize ? 0 : minSize; //易错
//	}
//};