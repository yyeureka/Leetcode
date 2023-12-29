#include "head.h"

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]

解题思路：
preorder traversal，但用queue buffer和output
*/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (NULL == root) return{};

		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> v;
			int len = q.size();  // 这是关键点
			for (int i = 0; i < len; i++) {
				root = q.front();
				q.pop();

				v.push_back(root->val);
				if (root->left) q.push(root->left);
				if (root->right) q.push(root->right);
			}
			res.push_back(v);
		}
		return res;
	}
};