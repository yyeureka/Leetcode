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
Numbers in a combination a1, a2, �� , ak must be in non-descending order. (ie, a1 �� a2 �� �� �� ak)
Different combinations can be in any order.
The solution set must not contain duplicate combinations.

����˼·��
���ظ���������ѡ�ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���

�����⣺
#39          ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳������ͬ���
#40/lint153  ���ظ���������ѡ�ظ�����һ����ֻ����һ�Σ���ͬ����ͬ˳������ͬ���
#216         ���ظ���1~9��һ����ֻ����һ�Σ���ʹ��k����
#377/lint564 ���ظ�����һ�������ظ�ʹ�ã���ͬ����ͬ˳���㲻ͬ���

*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		sort(candidates.begin(), candidates.end()); //���ظ���
		helper(candidates, 0, target, cur, result);

		return result;
	}

	void helper(vector<int> &candidates, int index, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (0 == target) {
			result.push_back(cur);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (i > 0 && candidates[i] == candidates[i - 1]) continue; //����ѡ�ظ�����ע����#40����
			if (target < candidates[i]) break;

			cur.push_back(candidates[i]);
			helper(candidates, i, target - candidates[i], cur, result); //һ�������ظ�ʹ��
			cur.pop_back();
		}
	}
};