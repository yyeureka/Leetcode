#include "head.h"

/*
Given a binary tree, return the postorder traversal of its nodes' values.
Follow up: Recursive solution is trivial, could you do it iteratively?

Example:
Input: [1,null,2,3]
1
\
2
/
3
Output: [3,2,1]

解题思路：
recursion，简单明了效率低
iterative*2
1、双栈法，要实现左->右->根输出，实现根->右->左的遍历再逆序输出
2、先遍历到左下，再处理右节点，将处理过的右节点标记，以防重复处理

Morris算法，O(1)空间复杂度
*/

// iterative双栈法1
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (NULL == root) return{};

		vector<int> res;
		vector<TreeNode*> v(1, root);

		while (!v.empty()) {
			root = v.back();
			v.pop_back();

			res.insert(res.begin(), root->val); //或return前整体reverse
			if (root->left) v.push_back(root->left);
			if (root->right) v.push_back(root->right);  // 与preorder的差别在这三行
		}
		return res;
	}
};

// iterative双栈法2
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		if (NULL == root) return{};
//
//		vector<int> res;
//		vector<TreeNode*> v;
//
//		while (root || !v.empty()) {
//			while (root) {
//				res.insert(res.begin(), root->val); //或return前整体reverse
//
//				v.push_back(root);
//				root = root->right;
//			}
//
//			root = v.back();
//			v.pop_back();
//
//			root = root->left;
//		}
//
//		return res;
//	}
//};

// recursive
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> res;
//		traversal(root, res);
//		return res;
//	}
//
//	void traversal(TreeNode* node, vector<int>& res) {
//		if (NULL == node) return;
//		traversal(node->left, res);
//		traversal(node->right, res);
//		res.push_back(node->val);
//	}
//};

////Morris
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode * root) {
//		vector<int> res;
//		TreeNode * cur = NULL;
//
//		while (root) {
//			if (root->right) {
//				cur = root->right;
//				while (cur->left && cur->left != root) cur = cur->left;
//
//				if (cur->left == root) {
//					cur->left = NULL;
//					root = root->left;
//				}
//				else {
//					res.push_back(root->val);
//					cur->left = root;
//					root = root->right;
//				}
//			}
//			else {
//				res.push_back(root->val);
//				root = root->left;
//			}
//		}
//
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};

// iterative 复杂易出错
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> res;
//		vector<TreeNode*> v;
//		TreeNode* pre = NULL;
//		while (root || !v.empty()) {
//			while (root) {
//				v.push_back(root);
//				root = root->left;
//			}
//			root = v.back();
//			if ((NULL == root->right) || (pre == root->right)) {  // 没有右节点或右节点已经处理过了
//				res.push_back(root->val);
//				v.pop_back();
//				pre = root;
//				root = NULL;  // 这句很重要，不然root要重复处理
//			}
//			else root = root->right;
//		}
//		return res;
//	}
//};