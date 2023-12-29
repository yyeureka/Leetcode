#include "head.h"

/*
Given a set of candidtate numbers candidates and a target number target. Find all unique combinations in candidates where the numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Example 1:
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[7], [2, 2, 3]]
Example 2:
Input: candidates = [1], target = 3
Output: [[1, 1, 1]]

Notice
All numbers (including target) will be positive integers.
Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak)
Different combinations can be in any order.
The solution set must not contain duplicate combinations.

解题思路：
有重复数，不能选重复数，一个数能重复使用，相同数不同顺序算相同组合

类似题：
#39          无重复数，一个数能重复使用，相同数不同顺序算相同组合
#40/lint153  有重复数，可以选重复数，一个数只能用一次，相同数不同顺序算相同组合
#216         无重复数1~9，一个数只能用一次，需使用k个数
#377/lint564 无重复数，一个数能重复使用，相同数不同顺序算不同组合

*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		sort(candidates.begin(), candidates.end()); //有重复数
		helper(candidates, 0, target, cur, result);

		return result;
	}

	void helper(vector<int> &candidates, int index, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (0 == target) {
			result.push_back(cur);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (i > 0 && candidates[i] == candidates[i - 1]) continue; //不能选重复数，注意与#40区别
			if (target < candidates[i]) break;

			cur.push_back(candidates[i]);
			helper(candidates, i, target - candidates[i], cur, result); //一个数能重复使用
			cur.pop_back();
		}
	}
};