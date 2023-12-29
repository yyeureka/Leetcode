#include "head.h"

/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
2
/ \
1   3
Output: true
Example 2:
5
/ \
1   4
/ \
3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
is 5 but its right child's value is 4.

解题思路：BST inorder traversal的结果是non-decreasing数列
interative/recursive，TreeNode *pre记录上一个node
*/

class Solution {
private:
	TreeNode * pre = NULL;
public:
	bool dfs(TreeNode * root) {
		if (NULL == root) return true;

		if (!dfs(root->left)) return false;
		if (pre && root->val <= pre->val) return false;
		pre = root;
		return dfs(root->right);
	}

	bool isValidBST(TreeNode * root) {
		return dfs(root);
	}
};

//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		vector<TreeNode*> v;
//		TreeNode* pre = NULL;  // 不初始化NULL会内存出错！
//
//		while (root || !v.empty()) {
//			while (root) {
//				v.push_back(root);
//				root = root->left;
//			}
//
//			root = v.back();
//			v.pop_back();
//
//			if (pre && (root->val <= pre->val)) return false;  // 一开始pre为NULL，需要pre不为NULL的条件
//			
//			pre = root;
//			root = root->right;
//		}
//
//		return true;
//	}
//};