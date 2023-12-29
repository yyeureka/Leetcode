#include "head.h"

/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Example:
Input:
1
/   \
2     3
\
5
Output: ["1->2->5", "1->3"]
Explanation: All root-to-leaf paths are: 1->2->5, 1->3

解题思路：
1、dfs
*/

//dfs
class Solution {
public:
	vector<string> res;

	vector<string> binaryTreePaths(TreeNode * root) {
		if (NULL == root) return{};

		helper(root, "");

		return res;
	}

	void helper(TreeNode * root, string cur) {
		if (NULL == root) return;

		cur += to_string(root->val);

		if (NULL == root->left && NULL == root->right) res.push_back(cur);
		if (root->left) helper(root->left, cur + "->");
		if (root->right) helper(root->right, cur + "->");
	}
};