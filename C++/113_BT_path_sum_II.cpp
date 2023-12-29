#include "head.h"

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
Return:
[
[5,4,11,2],
[5,8,4,5]
]

解题思路：对每一个node，push进临时vector，等递归处理完他的子node，要记得pop出来
*/

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> v;
		get(root, sum, res, v);
		return res;
	}

	void get(TreeNode* node, int sum, vector<vector<int>> &res, vector<int> &v) {
		if (NULL == node) return;
		v.push_back(node->val);
		sum -= node->val;
		if (NULL == node->left && NULL == node->right && 0 == sum) {
			res.push_back(v);
		}
		else {
			get(node->left, sum, res, v);
			get(node->right, sum, res, v);
		}
		v.pop_back();
	}
};