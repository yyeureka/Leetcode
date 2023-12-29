#include "head.h"
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]

解题思路：BFS&DFS，最后一起reverse比insert效率高
*/

//BFS
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (NULL == root) return{};

		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> v;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);

				v.push_back(cur->val);
			}
			res.push_back(v);
		}
		reverse(res.begin(), res.end());
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
//		else res[depth - 1].push_back(root->val);
//
//		if (root->left) dfs(root->left, depth + 1, res);
//		if (root->right) dfs(root->right, depth + 1, res);
//	}
//
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		if (NULL == root) return{};
//
//		vector<vector<int>> res;
//		dfs(root, 1, res);
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};