#include "head.h"

/*
Given a binary tree, return the inorder traversal of its nodes' values.
Follow up: Recursive solution is trivial, could you do it iteratively?

Example:
Input: [1,null,2,3]
1
\
2
/
3
Output: [1,3,2]

解题思路：
recursion/iteration
Morris算法，O(1)空间复杂度
*/

// iteration
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		vector<TreeNode*> v;
		while (root || !v.empty()) {
			while (root) {
				v.push_back(root);

				root = root->left;
			}

			root = v.back();
			v.pop_back();
			res.push_back(root->val);

			root = root->right;
		}
		return res;
	}
};

// recursion
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> res;
//
//		dfs(root, res);
//
//		return res;
//	}
//private:
//	void dfs(TreeNode* root, vector<int> &res) {
//		if (NULL == root) return;
//
//		if (root->left) dfs(root->left, res);
//		res.push_back(root->val);
//		if (root->right) dfs(root->right, res);
//	}
//};

////Morris算法
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode * root) {
//		vector<int> res;
//		TreeNode * cur = NULL;
//
//		while (root) {
//			if (root->left) {
//				cur = root->left;
//				while (cur->right && cur->right != root) cur = cur->right;
//
//				if (cur->right == root) {
//					res.push_back(root->val);
//					cur->right = NULL;
//					root = root->right;
//				}
//				else {
//					cur->right = root;
//					root = root->left;
//				}
//			}
//			else {
//				res.push_back(root->val);
//				root = root->right;
//			}
//		}
//
//		return res;
//	}
//};