#include "head.h"

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

解题思路：
无重复数1~9，一个数只能用一次，需使用k个数

类似题：
lint135      有重复数，不能选重复数，一个数能重复使用，相同数不同顺序算相同组合
#39          无重复数，一个数能重复使用，相同数不同顺序算相同组合
#40/lint153  有重复数，可以选重复数，一个数只能用一次，相同数不同顺序算相同组合
#377/lint564 无重复数，一个数能重复使用，相同数不同顺序算不同组合
*/

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> cur;
		vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

		helper(nums, 0, n, k, cur, result);

		return result;
	}

	void helper(vector<int> &nums, int index, int target, int size, vector<int> &cur, vector<vector<int>> &result) {
		if (cur.size() == size) {
			if (0 == target) {
				result.push_back(cur);
			}
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			if (target < nums[i]) break;

			cur.push_back(nums[i]);
			helper(nums, i + 1, target - nums[i], size, cur, result);
			cur.pop_back();
		}

	}
};