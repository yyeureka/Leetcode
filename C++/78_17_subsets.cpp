#include "head.h"

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

解题思路：
1、dfs组合经典方法，从之后的数中选一个加进cur再dfs
2、BFS:
subs初始为[]
输入1时为[],[1]
输入2时为[],[1],[2],[1,2]
输入3时为[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
依次加在末尾
3、dfs2，对每一个数，选或不选分别dfs
4、位运算，共2^n个组合，每一位的1代表选对应的那一个数
*/

//dfs经典方法
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> subs;
		vector<int> sub;

		sort(nums.begin(), nums.end()); //易错
		dfs(subs, sub, nums, 0);

		return subs;
	}

	void dfs(vector<vector<int>> &subs, vector<int> &sub, vector<int>& nums, int idx) {
		subs.push_back(sub);

		for (int i = idx; i < nums.size(); i++) {
			sub.push_back(nums[i]);
			dfs(subs, sub, nums, i + 1); //易错，不是idx+1
			sub.pop_back();
		}
	}
};

////dfs2
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int> &nums) {
//		vector<vector<int>> res;
//		vector<int> cur = {};
//
//		sort(nums.begin(), nums.end());
//		helper(nums, 0, cur, res);
//
//		return res;
//	}
//
//	void helper(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &res) {
//		if (idx == nums.size()) {
//			res.push_back(cur);
//			return;
//		}
//
//		cur.push_back(nums[idx]); //选当前数
//		helper(nums, idx + 1, cur, res);
//
//		cur.pop_back(); //不选当前数
//		helper(nums, idx + 1, cur, res);
//	}
//};

////bfs
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> res = { {} }; //易错，不是{}
//
//		sort(nums.begin(), nums.end()); //超贱，subsets需non decreasing，但nums可能乱序
//		for (int i : nums) {
//			int size = res.size();
//
//			for (int j = 0; j < size; j++) {
//				res.push_back(res[j]);
//				res.back().push_back(i);
//			}
//		}
//
//		return res;
//	}
//};

//位运算
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int> &nums) {
//		vector<vector<int>> res;
//		int n = nums.size();
//
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i < (1 << n); i++) { //共2^n个组合
//			vector<int> cur;
//
//			for (int j = 0; j < n; j++) {
//				if (0 == (i & (1 << j))) continue; //易错，不能少括号
//
//				cur.push_back(nums[j]);
//			}
//
//			res.push_back(cur);
//		}
//
//		return res;
//	}
//};