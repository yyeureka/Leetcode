#include "head.h"

/*
Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

Example 1:
Input:  tree = {}, node = 1
Output:  1
Explanation:
Insert node 1 into the empty tree, so there is only one node on the tree.
Example 2:
Input: tree = {2,1,4,3}, node = 6
Output: {2,1,4,3,6}
Explanation:
Like this:
2             2
/ \           / \
1   4   -->   1   4
/             / \
3             3   6

Challenge
Can you do it without recursion?

Notice
You can assume there is no duplicate values in this tree + node.
*/

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (NULL == root) return new TreeNode(val); //Ò×´í

		if (val > root->val) root->right = insertIntoBST(root->right, val);
		else root->left = insertIntoBST(root->left, val);

		return root;
	}
};

//class Solution {
//public:
//	TreeNode * insertNode(TreeNode * root, TreeNode * node) {
//		if (NULL == root) return node;
//
//		TreeNode * res = root;
//
//		while (1) {
//			if (node->val > root->val) {
//				if (root->right) root = root->right;
//				else {
//					root->right = node;
//					break;
//				}
//			}
//			else {
//				if (root->left) root = root->left;
//				else {
//					root->left = node;
//					break;
//				}
//			}
//		}
//
//		return res;
//	}
//};