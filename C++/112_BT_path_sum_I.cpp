#include "head.h"

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

解题思路：注意输入[]和0时返回的是false
*/

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (NULL == root) return false;  //这里非常tricky,输入[]和0不是返回true
		if (NULL == root->left && NULL == root->right) return sum == root->val;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};