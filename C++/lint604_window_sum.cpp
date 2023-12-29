#include <vector>
using namespace std;

/*
Given an array of n integers, and a moving window(size k), move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.

Example 1
Input：array = [1,2,7,8,5], k = 3
Output：[10,17,20]
Explanation：
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20

解题思路：
1、普通windows
2、同向双指针
*/

class Solution {
public:
	vector<int> winSum(vector<int> &nums, int k) {
		if (nums.empty() || k > nums.size()) return{};

		vector<int> res;
		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (i >= k) sum -= nums[i - k];

			if (i >= k - 1) res.push_back(sum);
		}

		return res;
	}
};

//class Solution {
//public:
//	vector<int> winSum(vector<int> &nums, int k) {
//		if (nums.empty() || k > nums.size()) return{};
//
//		int left = 0;
//		int right = 0;
//		int sum = 0;
//		vector<int> res;
//
//		while (right < nums.size()) {
//			sum += nums[right++];
//			if (right - left > k) sum -= nums[left++];
//
//			if (right >= k) res.push_back(sum);
//		}
//
//		return res;
//	}
//};