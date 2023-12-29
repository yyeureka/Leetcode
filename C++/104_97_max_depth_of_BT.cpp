#include "head.h"

/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its depth = 3.

解题思路：
1、divide&conquer，类似#111
2、traverse
*/

//divide conquer
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (NULL == root) return 0;

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

//traverse
//class Solution {
//public:
//	void dfs(TreeNode * root, int curDepth, int &maxDepth) {
//		if (NULL == root) return;
//
//		if (curDepth > maxDepth) maxDepth = curDepth;
//		dfs(root->left, curDepth + 1, maxDepth);
//		dfs(root->right, curDepth + 1, maxDepth);
//	}
//
//	int maxDepth(TreeNode * root) {
//		int res = 0;
//
//		dfs(root, 1, res);
//
//		return res;
//	}
//};