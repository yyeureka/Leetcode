#include "head.h"

/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Example1
Inpurt:  {3,9,20,#,#,15,7}
Output: [[9],[3,15],[20],[7]]
Explanation:
3
/\
/  \
9  20
/\
/  \
15   7
Example2
Input: {3,9,8,4,0,1,7}
Output: [[4],[9],[3,0,1],[8],[7]]
Explanation:
3
/\
/  \
9   8
/\  /\
/  \/  \
4  01   7

解题思路：
遍历，treemap记录并排序
lintcode：相同位置的两个node根据从左到右排序，treemap按列排序，BFS实现按行排序
leetcode：相同位置的两个node根据从大到小排序，treemap按列、行、数字排序
*/

//lintcode
class Solution {
public:
	vector<vector<int>> verticalOrder(TreeNode * root) {
		if (NULL == root) {
			return{};
		}

		map<int, vector<int>> level;
		queue<pair<TreeNode *, int>> q;
		q.push({ root, 0 });

		while (!q.empty()) {
			TreeNode * cur = q.front().first;
			int index = q.front().second;
			q.pop();

			level[index].push_back(cur->val);

			if (cur->left) {
				q.push({ cur->left, index - 1 });
			}
			if (cur->right) {
				q.push({ cur->right, index + 1 });
			}
		}

		vector<vector<int>> results;

		for (auto i : level) {
			results.push_back(i.second);
		}

		return results;
	}
};

//leetcode
//class Solution {
//public:
//	struct cmp {
//		bool operator()(pair<int, int> a, pair<int, int> b) {
//			if (a.first != b.first) {
//				return a.first < b.first;
//			}
//			return a.second < b.second;
//		}
//	};
//
//	vector<vector<int>> verticalTraversal(TreeNode* root) {
//		if (NULL == root) {
//			return{};
//		}
//
//		map<int, map<int, set<int>>> memo;
//		queue<pair<TreeNode *, int>> q;
//		q.push({ root, 0 });
//		int level = 0;
//
//		while (!q.empty()) {
//			int size = q.size();
//
//			for (int i = 0; i < size; i++) {
//				TreeNode * cur = q.front().first;
//				int index = q.front().second;
//				q.pop();
//
//				memo[index][level].insert(cur->val);
//
//				if (cur->left) {
//					q.push({ cur->left, index - 1 });
//				}
//				if (cur->right) {
//					q.push({ cur->right, index + 1 });
//				}
//			}
//
//			level++;
//		}
//
//		vector<vector<int>> results;
//
//		for (auto i : memo) {
//			results.push_back({});
//
//			for (auto j : i.second) {
//				for (int k : j.second) {
//					results.back().push_back(k);
//				}
//			}
//		}
//
//		return results;
//	}
//};