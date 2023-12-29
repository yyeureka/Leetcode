#include <vector>
#include <algorithm>
using namespace std;

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

解题思路：类似#78，解决重复的方法是先排序，碰到相同的元素跳过
1、DFS组合经典方法
2、BFS
*/

//dfs
class Solution {
public:
	void dfs(vector<vector<int>> &subs, vector<int> &sub, vector<int>& nums, int begin) {
		subs.push_back(sub);

		for (int i = begin; i < nums.size(); i++) {
			if (i > begin && nums[i] == nums[i - 1]) continue; //比unique序列多这一句

			sub.push_back(nums[i]);
			dfs(subs, sub, nums, i + 1);
			sub.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> subs;
		vector<int> sub;

		sort(nums.begin(), nums.end()); //易错
		dfs(subs, sub, nums, 0);

		return subs;
	}
};

////bfs
//class Solution {
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		vector<vector<int>> subs = { {} };
//		vector<int> lastDigit = { -1 };
//
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i < nums.size(); i++) {
//			int size = subs.size();
//
//			for (int j = 0; j < size; j++) {
//				if (i > 0 && nums[i] == nums[i - 1] && lastDigit[j] != i - 1) continue; //选了前一个相同的元素才能选现在这个
//
//				subs.push_back(subs[j]);
//				subs.back().push_back(nums[i]);
//				lastDigit.push_back(i);
//			}
//		}
//
//		return subs;
//	}
//};
