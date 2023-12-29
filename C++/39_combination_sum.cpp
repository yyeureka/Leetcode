#include "head.h"

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
[7],
[2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]

解题思路：
无重复数，一个数能重复使用，相同数不同顺序算相同组合

类似题：
lint135      有重复数，不能选重复数，一个数能重复使用，相同数不同顺序算相同组合
#40/lint153  有重复数，可以选重复数，一个数只能用一次，相同数不同顺序算相同组合
#216         无重复数1~9，一个数只能用一次，需使用k个数
#377/lint564 无重复数，一个数能重复使用，相同数不同顺序算不同组合
*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		helper(candidates, 0, target, cur, result); //没有重复数

		return result;
	}

	void helper(vector<int> &candidates, int index, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (0 == target) {
			result.push_back(cur);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (target < candidates[i]) continue; //没sort所以不能break

			cur.push_back(candidates[i]);
			helper(candidates, i, target - candidates[i], cur, result); //一个数可以重复使用
			cur.pop_back();
		}
	}
};