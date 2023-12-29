#include <vector>
using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.
Follow up: Recursive solution is trivial, could you do it iteratively?

Example:
Input: [1,null,2,3]
1
\
2
/
3
Output: [1,2,3]

解题思路：
递归一种，迭代两种
Morris算法，O(1)空间复杂度
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iterative 1
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (NULL == root) return{};

		vector<int> res;
		vector<TreeNode*> v(1, root);

		while (!v.empty()) {
			root = v.back();
			v.pop_back();

			res.push_back(root->val);
			if (root->right) v.push_back(root->right);  // 右节点先入栈，后出栈
			if (root->left) v.push_back(root->left);
		}
		return res;
	}
};

// iterative 2
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> res;
//		vector<TreeNode*> v;
//
//		while (root || !v.empty()) {
//			while (root) {
//				res.push_back(root->val);  // 与inorder的差别仅为打印节点的timing不一样
//				v.push_back(root);
//
//				root = root->left;
//			}
//
//			root = v.back();
//			v.pop_back();
//
//			root = root->right;
//		}
//		return res;
//	}
//};

// recursive
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> res;
//		dfs(root, res);
//		return res;
//	}
//
//	void dfs(TreeNode* root, vector<int> &res) {
//		if (NULL == root) return;
//
//		res.push_back(root->val);
//		dfs(root->left, res);
//		dfs(root->right, res);
//	}
//};

////Morris
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode * root) {
//		vector<int> res;
//		TreeNode * cur = NULL;
//
//		while (root) {
//			if (root->left) {
//				cur = root->left;
//				while (cur->right && cur->right != root) cur = cur->right;
//
//				if (cur->right == root) {
//					cur->right = NULL;
//					root = root->right;
//				}
//				else {
//					res.push_back(root->val);
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