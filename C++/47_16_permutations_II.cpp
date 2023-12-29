#include <vector>
#include <algorithm>
using namespace std;

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

解题思路：类似#46，因为有重复，先sort，交换的时候不交换相同的元素
1、dfs排列经典方法
2、dfs swap方法
*/

//dfs经典方法
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		if (nums.empty()) return{ {} }; //易错

		vector<vector<int>> results;
		vector<int> cur;
		vector<bool> visited(nums.size(), false); //已选列表，false为未选

		sort(nums.begin(), nums.end());
		helper(nums, visited, cur, results);

		return results;
	}

	void helper(vector<int> &nums, vector<bool> &visited, vector<int> &cur, vector<vector<int>> &results) {
		if (cur.size() == nums.size()) {
			results.push_back(cur);
			return;
		}

		for (int i = 0; i < visited.size(); i++) {
			if (visited[i]) continue;
			if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

			cur.push_back(nums[i]);
			visited[i] = true;
			helper(nums, visited, cur, results);
			visited[i] = false;
			cur.pop_back();
		}
	}
};

//swap
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int> &nums) {
//		if (nums.empty()) return{ {} };
//
//		vector<vector<int>> results;
//
//		sort(nums.begin(), nums.end());
//		helper(nums, 0, results);
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
//			if (i > idx && nums[i] == nums[idx]) continue;
//
//			swap(nums[i], nums[idx]);
//			helper(nums, idx + 1, results);
//		}
//	}
//};