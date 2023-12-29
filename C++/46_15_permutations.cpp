#include "head.h"

/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]

解题思路：
1、dfs排列经典方法
2、iteration方法：一直调用找下一个排列的函数，直到next=input为止
3、dfs，依次两两swap并做dfs
*/

//dfs经典方法
class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums) {
		if (nums.empty()) return{ {} }; //易错

		vector<vector<int>> results;
		vector<int> cur;
		vector<bool> visited(nums.size(), false); //已选列表，false为未选

		helper(nums, visited, cur, results); //unique时不需要sort

		return results;
	}

	void helper(vector<int> &nums, vector<bool> &visited, vector<int> &cur, vector<vector<int>> &results) {
		if (cur.size() == nums.size()) {
			results.push_back(cur);
			return;
		}

		for (int i = 0; i < visited.size(); i++) {
			if (visited[i]) continue;

			cur.push_back(nums[i]);
			visited[i] = true;
			helper(nums, visited, cur, results);
			visited[i] = false;
			cur.pop_back();
		}
	}
};

//swap1
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int> &nums) {
//		if (nums.empty()) return{ {} };
//
//		vector<vector<int>> results;
//
//		helper(nums, 0, results); //没有重复的时候就不用sort了
//
//		return results;
//	}
//
//	void helper(vector<int> nums, int idx, vector<vector<int>> &results) {
//		if (idx == nums.size()) {
//			results.push_back(nums);
//			return;
//		}
//
//		for (int i = idx; i < nums.size(); i++) {
//			swap(nums[i], nums[idx]); //当前层会互相影响，nums不取reference保证不同层不会互相影响
//			helper(nums, idx + 1, results);
//		}
//	}
//};

//swap2
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int> &nums) {
//		if (nums.empty()) return{ {} }; //易错
//
//		vector<vector<int>> results;
//
//		sort(nums.begin(), nums.end());
//		helper(nums, 0, results);
//
//		return results;
//	}
//
//	void helper(vector<int> &nums, int idx, vector<vector<int>> &results) {
//		if (idx == nums.size()) {
//			results.push_back(nums);
//			return;
//		}
//
//		for (int i = idx; i < nums.size(); i++) {
//			swap(nums[i], nums[idx]);
//			helper(nums, idx + 1, results);
//			swap(nums[i], nums[idx]); //当前层和不同层都不会互相影响
//		}
//	}
//};

