#include "head.h"

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]

����˼·��
���ظ���������ѡ�ظ�����һ����ֻ����һ�Σ���ͬ����ͬ˳������ͬ���
����#90 subsetsII

�����⣺
lint135      ���ظ���������ѡ�ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
lin39        ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
#216         ���ظ���1~9��һ����ֻ����һ�Σ���ʹ��k����
#377/lint564 ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳���㲻ͬ���
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		sort(num.begin(), num.end()); //���ظ���
		helper(num, 0, target, cur, result);

		return result;
	}

	void helper(vector<int> &num, int index, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (0 == target) {
			result.push_back(cur);
			return;
		}

		for (int i = index; i < num.size(); i++) {
			if (i > index && num[i] == num[i - 1]) continue; //�ظ���ȥ��
			if (target < num[i]) break;

			cur.push_back(num[i]);
			helper(num, i + 1, target - num[i], cur, result); //һ����ֻ����һ��
			cur.pop_back();
		}
	}
};