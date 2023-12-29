#include "head.h"

/*
Invert a binary tree.

Example:
Input:
4
/   \
2     7
/ \   / \
1   3 6   9
Output:
4
/   \
7     2
/ \   / \
9   6 3   1
*/

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (NULL == root) return NULL;

		TreeNode * tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};

//class Solution {
//public:
//	TreeNode* invertTree(TreeNode* root) {
//		if (NULL == root) return NULL;
//
//		TreeNode *tmp = root->left;
//		root->left = root->right;
//		root->right = tmp;
//
//		invertTree(root->left);
//		invertTree(root->right);
//		return root;
//	}
//};