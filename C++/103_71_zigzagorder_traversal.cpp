#include "head.h"

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]

解题思路：类似level-order，奇数排reverse，BFS&DFS
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
		if (NULL == root) return{};

		vector<vector<int>> res;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> v;
			for (int i = 0; i < size; i++) {
				TreeNode * cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);

				v.push_back(cur->val);
			}

			if (res.size() & 1) reverse(v.begin(), v.end());
			res.push_back(v);
		}
		return res;
	}
};

////DFS
//class Solution {
//public:
//	void dfs(TreeNode * root, int depth, vector<vector<int>> &res) {
//		if (NULL == root) return;
//
//		if (depth > res.size()) res.push_back({ root->val });
//		else {
//			if (depth & 1) res[depth - 1].push_back(root->val);
//			else res[depth - 1].insert(res[depth - 1].begin(), root->val);
//		}
//
//		if (root->left) dfs(root->left, depth + 1, res);
//		if (root->right) dfs(root->right, depth + 1, res);
//	}
//
//	vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
//		if (NULL == root) return{};
//
//		vector<vector<int>> res;
//		dfs(root, 1, res);
//		return res;
//	}
//};