#include "head.h"

/*
Given a binary search tree and a range [k1, k2], return node values within a given range in ascending order.

Example 1:
Input£º{5},6,10
Output£º[]
5
it will be serialized {5}
No number between 6 and 10
Example 2:
Input£º{20,8,22,4,12},10,22
Output£º[12,20,22]
Explanation£º
20
/  \
8   22
/ \
4   12
it will be serialized {20,8,22,4,12}
[12,20,22] between 10 and 22
*/

class Solution {
public:
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		vector<int> res;

		helper(root, k1, k2, res);

		return res;
	}

	void helper(TreeNode * root, int k1, int k2, vector<int> &res) {
		if (NULL == root) return;

		if (root->val < k1) helper(root->right, k1, k2, res);
		else if (root->val > k2) helper(root->left, k1, k2, res);
		else {
			res.push_back(root->val);

			helper(root->right, k1, k2, res);
			helper(root->left, k1, k2, res);
		}
	}
};

//class Solution {
//public:
//	vector<int> searchRange(TreeNode * root, int k1, int k2) {
//		if (NULL == root) return{};
//
//		vector<int> res;
//		stack<TreeNode *> s;
//
//		while (root || !s.empty()) {
//			while (root) {
//				s.push(root);
//				root = root->left;
//			}
//
//			root = s.top();
//			s.pop();
//
//          if (root->val > k2) break;
//			if (root->val >= k1 && root->val <= k2) res.push_back(root->val);
//
//			root = root->right;
//		}
//
//		return res;
//	}
//};