#include "head.h"

/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Example1
Input: root = {5,4,9,2,#,8,10} and target = 6.124780
Output: 5
Explanation：
Binary tree {5,4,9,2,#,8,10},  denote the following structure:
5
/ \
4    9
/    / \
2    8  10
Example2
Input: root = {3,2,4,1} and target = 4.142857
Output: 4
Explanation：
Binary tree {3,2,4,1},  denote the following structure:
3
/ \
2    4
/
1

Notice
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

解题思路：
1、bs找上下限，时间复杂度平均O(logn)
2、inorder traversal
*/

class Solution {
public:
	int closestValue(TreeNode * root, double target) {
		TreeNode * upper = upperBound(root, target);
		TreeNode * lower = lowerBound(root, target);

		if (NULL == upper) return lower->val;
		if (NULL == lower) return upper->val;
		if (upper->val - target < target - lower->val) return upper->val;
		return lower->val;
	}

	TreeNode * upperBound(TreeNode * root, double target) {
		if (NULL == root) return NULL;

		if (root->val < target) return upperBound(root->right, target); //易错
		if (root->val == target) return root;

		TreeNode * node = upperBound(root->left, target);

		return node ? node : root;
	}

	TreeNode * lowerBound(TreeNode * root, double target) {
		if (NULL == root) return NULL;

		if (root->val > target) return lowerBound(root->left, target); //易错
		if (root->val == target) return root;

		TreeNode * node = lowerBound(root->right, target);

		return node ? node : root;
	}
};

//class Solution {
//public:
//	int closestValue(TreeNode * root, double target) {
//		int pre = INT_MAX;
//		stack<TreeNode *> s;
//
//		while (root || !s.empty()) {
//			while (root) {
//				s.push(root);
//
//				root = root->left;
//			}
//
//			root = s.top();
//			s.pop();
//
//			if (target == root->val) return root->val;
//			if (root->val > target) {
//				if (INT_MAX == pre) return root->val;
//				return abs(pre - target) > abs(root->val - target) ? root->val : pre;
//			}
//
//			pre = root->val;
//			root = root->right;
//		}
//
//		return pre; //极易错！比最后一个node都大的情况
//	}
//};