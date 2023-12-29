#include "head.h"

/*
Given n unique postive integers, number k (1<=k<=n) and target.
Find all possible k integers where their sum is target.

Example 1:
Input: [1,2,3,4], k = 2, target = 5
Output:  [[1,4],[2,3]]
Example 2:
Input: [1,3,4,6], k = 3, target = 8
Output:  [[1,3,4]]

解题思路：#216异曲同工
*/

class Solution {
public:
	vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
		vector<vector<int>> result;
		vector<int> cur;

		helper(A, 0, k, target, cur, result);

		return result;
	}

	void helper(vector<int> &A, int index, int size, int target, vector<int> &cur, vector<vector<int>> &result) {
		if (cur.size() == size) {
			if (0 == target) {
				result.push_back(cur);
			}
			return;
		}

		for (int i = index; i < A.size(); i++) {
			if (A[i] > target) continue;

			cur.push_back(A[i]);
			helper(A, i + 1, size, target - A[i], cur, result);
			cur.pop_back();
		}

	}
};