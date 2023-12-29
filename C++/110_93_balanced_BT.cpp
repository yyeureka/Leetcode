#include "head.h"

/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:
3
/ \
9  20
/  \
15   7
Return true.
Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
1
/ \
2   2
/ \
3   3
/ \
4   4
Return false.
*/

// bottom up
class Solution {
private:
	#define NOT_BALANCED -1
public:
	bool isBalanced(TreeNode* root) {
		if (NULL == root) return true; //рв╢М

		return NOT_BALANCED != depth(root);
	}

	int depth(TreeNode* node) {
		if (NULL == node) return 0;

		int left = depth(node->left);
		if (NOT_BALANCED == left) return NOT_BALANCED;

		int right = depth(node->right);
		if (NOT_BALANCED == right) return NOT_BALANCED;

		if (abs(left - right) > 1) return NOT_BALANCED;

		return max(left, right) + 1;
	}
};

////top to down
//class Solution {
//public:
//	bool isBalanced(TreeNode* root) {
//		if (NULL == root) return true;
//
//		if (abs(depth(root->left) - depth(root->right)) > 1) return false;
//		return isBalanced(root->left) && isBalanced(root->right);
//	}
//
//	int depth(TreeNode* node) {
//		if (NULL == node) return 0;
//
//		return max(depth(node->left), depth(node->right)) + 1;
//	}
//};