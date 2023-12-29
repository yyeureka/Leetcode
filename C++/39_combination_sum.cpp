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

����˼·��
���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���

�����⣺
lint135      ���ظ���������ѡ�ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
#40/lint153  ���ظ���������ѡ�ظ�����һ����ֻ����һ�Σ���ͬ����ͬ˳������ͬ���
#216         ���ظ���1~9��һ����ֻ����һ�Σ���ʹ��k����
#377/lint564 ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳���㲻ͬ���
*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		helper(candidates, 0, target, cur, result); //û���ظ���

		return result;
	}

	void helper(vector<int> &candidates, int index, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (0 == target) {
			result.push_back(cur);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (target < candidates[i]) continue; //ûsort���Բ���break

			cur.push_back(candidates[i]);
			helper(candidates, i, target - candidates[i], cur, result); //һ���������ظ�ʹ��
			cur.pop_back();
		}
	}
};