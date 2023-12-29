#include "head.h"

/*
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example1
Input:
[-3,1,1,-3,5]
Output:
[0,2]
Explanation: [0,2], [1,3], [1,1], [2,2], [0,4]

Challenge
O(nlogn) time

Notice
It is guaranteed that the sum of any numbers is in [-2^{31},2^{31}-1]

解题思路：lint138变种
1、计算所有的prefixsum，记录对应的index
2、排序prefixsum
3、找到最接近的两个prefixsum
*/

bool cmp1(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
};

class Solution {
public:
	vector<int> subarraySumClosest(vector<int> &nums) {
		if (nums.empty()) {
			return{};
		}

		int sum = 0;
		vector<pair<int, int>> prefixSum;
		prefixSum.push_back({ 0, -1 });  //易错，初始化

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			prefixSum.push_back({ sum, i });
		}

		int diff = INT_MAX;
		vector<int> closest(2, 0);

		sort(prefixSum.begin(), prefixSum.end(), cmp1);
		for (int i = 1; i < prefixSum.size(); i++) {
			if (abs(prefixSum[i].first - prefixSum[i - 1].first) < diff) {
				diff = abs(prefixSum[i].first - prefixSum[i - 1].first);

				if (prefixSum[i].second > prefixSum[i - 1].second) { //易错
					closest[0] = prefixSum[i - 1].second + 1;
					closest[1] = prefixSum[i].second;
				}
				else {
					closest[0] = prefixSum[i].second + 1;
					closest[1] = prefixSum[i - 1].second;
				}
			}
		}

		return closest;
	}
};