#include "head.h"

/*
Given a root of Binary Search Tree with unique value for each node. Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. You should keep the tree still a binary search tree after removal.

Example 1
Input:
Tree = {5,3,6,2,4}
k = 3
Output: {5,2,6,#,4} or {5,4,6,2}
Explanation:
Given binary search tree:
5
/ \
3   6
/ \
2   4
Remove 3, you can either return:
5
/ \
2   6
\
4
or
5
/ \
4   6
/
2

Example 2
Input:
Tree = {5,3,6,2,4}
k = 4
Output: {5,3,6,2}
Explanation:
Given binary search tree:
5
/ \
3   6
/ \
2   4
Remove 4, you should return:
5
/ \
3   6
/
2
*/

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (NULL == root) return NULL;

		if (key > root->val) {
			root->right = deleteNode(root->right, key);
		}
		else if (key < root->val) {
			root->left = deleteNode(root->left, key);
		}
		else {
			if (NULL == root->left) return root->right;
			if (NULL == root->right) return root->left;

			int next = findNext(root->right);
			root->val = next;
			root->right = deleteNode(root->right, next);
		}

		return root;
	}

	int findNext(TreeNode * root) {
		while (root->left) {
			root = root->left;
		}

		return root->val;
	}
};