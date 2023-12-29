#include "head.h"

/*
Given a binary search tree and a number n, find two numbers in the tree that sums up to n.

Example1
Input:
{4,2,5,1,3}
3
Output: [1,2] (or [2,1])
Explanation:
binary search tree:
4
/ \
2   5
/ \
1   3
Example2
Input:
{4,2,5,1,3}
5
Output: [2,3] (or [3,2])

Notice
Without any extra space.

解题思路：
1、traverse每一个点，bs它的左/右subtree是否有加起来等于n的值
2、inorder traversal+set，有额外空间且时间复杂度O(n)
*/

class Solution {
public:
	vector<int> twoSum(TreeNode * root, int n) {
		if (NULL == root) return{};

		vector<int> res(2, -1);

		helper(root, n, res);

		return res;
	}

	void helper(TreeNode * root, int n, vector<int> &res) {
		if (NULL == root) return;

		if (root->val <= n / 2) {
			if (search(root->right, n - root->val)) {
				res[0] = root->val;
				res[1] = n - root->val;
				return;
			}
		}
		else {
			if (search(root->left, n - root->val)) {
				res[0] = n - root->val;
				res[1] = root->val;
				return;
			}
		}

		helper(root->left, n, res);
		helper(root->right, n, res);
	}

	bool search(TreeNode * root, int target) {
		if (NULL == root) return false;

		if (root->val > target) return search(root->left, target);
		else if (root->val < target) return search(root->right, target);
		else return true;
	}
};

//class Solution {
//public:
//	vector<int> twoSum(TreeNode * root, int n) {
//		stack<TreeNode *> s;
//		unordered_set<int> pre;
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
//			if (pre.find(n - root->val) != pre.end()) return{ n - root->val, root->val };
//			pre.insert(root->val);
//
//			root = root->right;
//		}
//
//		return{};
//	}
//};