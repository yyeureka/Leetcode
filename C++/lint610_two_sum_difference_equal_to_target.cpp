#include "head.h"

/*
Given an array of integers, find two numbers that their difference equals to a target value.
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

Example 1:
Input: nums = [2, 7, 15, 24], target = 5
Output: [1, 2]
Explanation:
(7 - 2 = 5)
Example 2:
Input: nums = [1, 1], target = 0
Output: [1, 2]
Explanation:
(1 - 1 = 0)

Notice
It's guaranteed there is only one available solution

解题思路：
1、hash，类似two sum
2、同向双指针，区别于two sum的相向双指针
*/

class Solution {
public:
	vector<int> twoSum7(vector<int> &nums, int target) {
		if (nums.empty()) return{};

		vector<int> res;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++) {
			if (m.find(target + nums[i]) != m.end()) {
				return{ m[target + nums[i]], i + 1 }; //idx是从1开始的！！
			}
			if (m.find(nums[i] - target) != m.end()) {
				return{ m[nums[i] - target], i + 1 };
			}

			if (m.find(nums[i]) == m.end()) m[nums[i]] = i + 1;
		}

		return{};
	}
};

//class Solution {
//public:
//	vector<int> twoSum7(vector<int> &nums, int target) {
//		if (nums.empty()) return{};
//
//		sort(nums.begin(), nums.end());
//		target = target > 0 ? target : -target; //极易错
//
//		int j = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			while (j < nums.size() && nums[j] - nums[i] < target) {
//				j++;
//			}
//
//			if (target == nums[j] - nums[i]) return{ nums[i], nums[j] }; //返回数值，idx做不到
//		}
//
//		return{};
//	}
//};