#include "head.h"

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
Note:
Bonus points if you could solve it both recursively and iteratively.

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
1
/ \
2   2
/ \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
1
/ \
2   2
\   \
3    3

解题思路：
recursion 左node值应等于右node值，左左等于右右，左右等于右左
iteration 将左左&右右，左右&右左push进栈中，每次取出两个比较
*/

// iterative
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (NULL == root) return true;
		vector<TreeNode*> v = { root->right, root->left };
		while (!v.empty()) {
			TreeNode* l = v.back();
			v.pop_back();
			TreeNode* r = v.back();
			v.pop_back();
			if (NULL == l && NULL == r) continue;   // 这里不能return true啊！！
			if (NULL == l || NULL == r) return false;
			if (l->val != r->val) return false;
			v.push_back(r->left);
			v.push_back(l->right);
			v.push_back(r->right);
			v.push_back(l->left);
		}
		return true;
	}
};

// recursive
//class Solution {
//public:
//	bool isSymmetric(TreeNode* root) {
//		if (NULL == root) return true;
//		return check(root->left, root->right);
//	}
//
//	bool check(TreeNode* left, TreeNode* right) {
//		if (NULL == left && NULL == right) return true;
//		if (NULL == left || NULL == right) return false;
//		return (left->val == right->val) && check(left->left, right->right) && check(left->right, right->left);
//	}
//};