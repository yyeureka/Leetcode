#include "head.h"

/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Example 1:
Input:
{1}
0.000000
1
Output:
[1]
Explanation：
Binary tree {1},  denote the following structure:
1
Example 2:
Input:
{3,1,4,#,2}
0.275000
2
Output:
[1,2]
Explanation：
Binary tree {3,1,4,#,2},  denote the following structure:
3
/  \
1    4
\
2

Challenge
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Notice
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

解题思路：
1、找到target附近的leaf node，将沿途node放入lower(<=target)和upper(>=target)
   类似lint460，通过getPre和getNext函数得到上一个/下一个node加进res
2、先inorder traverse出递增数列，再类似#658得到附近的k个数，O(n)
*/

class Solution {
public:
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		if (NULL == root) return{};

		TreeNode * cur = root;
		stack<TreeNode *> lower;
		while (cur) {
			lower.push(cur);
			cur = cur->right;
		}

		cur = root;
		stack<TreeNode *> upper;
		while (cur) {
			upper.push(cur);
			cur = cur->left;
		}

		while (!lower.empty() && lower.top()->val >= target) getPre(lower);
		while (!upper.empty() && upper.top()->val < target) getNext(upper);

		vector<int> res;
		for (int i = 0; i < k; i++) {
			if (!pickLeft(lower, upper, target)) {
				res.push_back(upper.top()->val);
				getNext(upper);
			}
			else {
				res.push_back(lower.top()->val);
				getPre(lower);
			}
		}

		return res;
	}

	void getPre(stack<TreeNode *> &stack) {
		TreeNode * node = stack.top();
		stack.pop();

		node = node->left;
		while (node) {
			stack.push(node);
			node = node->right;
		}
	}

	void getNext(stack<TreeNode *> &stack) {
		TreeNode * node = stack.top();
		stack.pop();

		node = node->right;
		while (node) {
			stack.push(node);
			node = node->left;
		}
	}

	bool pickLeft(stack<TreeNode *> lower, stack<TreeNode *> upper, double target) {
		if (lower.empty()) return false;
		if (upper.empty()) return true;
		if ((upper.top()->val - target) < (target - lower.top()->val)) return false;
		return true;
	}
};

//class Solution {
//public:
//	vector<int> closestKValues(TreeNode * root, double target, int k) {
//		if (NULL == root) return{};
//
//		vector<TreeNode *> lower = getStack(root, target);
//		vector<TreeNode *> upper(lower.begin(), lower.end());
//		if (lower.back()->val > target) getPre(lower); //关键点
//		else getNext(upper);
//
//		vector<int> res;
//		for (int i = 0; i < k; i++) {
//			if (!pickLeft(lower, upper, target)) {
//				res.push_back(upper.back()->val);
//				getNext(upper);
//			}
//			else {
//				res.push_back(lower.back()->val);
//				getPre(lower);
//			}
//		}
//
//		return res;
//	}
//
//	vector<TreeNode *> getStack(TreeNode * root, double target) {
//		if (NULL == root) return{};
//
//		vector<TreeNode *> res;
//
//		while (root) {
//			res.push_back(root);
//
//			if (root->val < target) root = root->right;
//			else root = root->left;
//		}
//
//		return res;
//	}
//
//	void getPre(vector<TreeNode *> &stack) {
//		TreeNode * node = stack.back();
//
//		if (NULL == node->left) {
//			stack.pop_back();
//
//			while (!stack.empty() && node == stack.back()->left) { //将>target的node都pop出去
//				node = stack.back();
//				stack.pop_back();
//			}
//		}
//		else {
//			node = node->left;
//			while (node) {
//				stack.push_back(node);
//				node = node->right;
//			}
//		}
//	}
//
//	void getNext(vector<TreeNode *> &stack) {
//		TreeNode * node = stack.back();
//
//		if (NULL == node->right) {
//			stack.pop_back();
//
//			while (!stack.empty() && node == stack.back()->right) {
//				node = stack.back();
//				stack.pop_back();
//			}
//		}
//		else {
//			node = node->right;
//			while (node) {
//				stack.push_back(node);
//				node = node->left;
//			}
//		}
//	}
//
//	bool pickLeft(vector<TreeNode *> lower, vector<TreeNode *> upper, double target) {
//		if (lower.empty()) return false;
//		if (upper.empty()) return true;
//		if ((upper.back()->val - target) < (target - lower.back()->val)) return false;
//		return true;
//	}
//};

//class Solution {
//public:
//	vector<int> closestKValues(TreeNode * root, double target, int k) {
//		vector<int> nums;
//		inOrder(root, nums);
//
//		int left = 0;
//		int right = nums.size() - k;
//		while (left + 1 < right) {
//			int mid = left + (right - left) / 2;
//
//			if (target - nums[mid] < nums[mid + k] - target) right = mid;
//			else left = mid;
//		}
//
//		if (nums[right + k - 1] - target < target - nums[left]) left = right;
//
//		return vector<int>(nums.begin() + left, nums.begin() + left + k);
//	}
//
//	void inOrder(TreeNode * root, vector<int> &nums) {
//		if (NULL == root) return;
//
//		inOrder(root->left, nums);
//		nums.push_back(root->val);
//		inOrder(root->right, nums);
//	}
//};