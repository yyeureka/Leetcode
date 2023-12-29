#include "head.h"

/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its minimum depth = 2.
*/

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (NULL == root) return 0;

		int left = minDepth(root->left);
		int right = minDepth(root->right);

		if (!left) return right + 1;
		if (!right) return left + 1;
		return min(left, right) + 1; //易错，上两个分支不能少，需要到leaf
	}
};