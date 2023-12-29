#include "head.h"

/*
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.
If the given node has no in-order successor in the tree, return null.

Example 1:
Input: {1,#,2}, node with value 1
Output: 2
Explanation:
1
\
2
Example 2:
Input: {2,1,3}, node with value 1
Output: 2
Explanation:
2
/ \
1   3
Binary Tree Representation

Challenge
O(h), where h is the height of the BST.

Notice
It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)

解题思路：
1、recursive BS方法，逻辑有点绕，O(h)时间
2、iterative reversal方法，O(h+k)时间
*/

//recursive BS
class Solution {
public:
	TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
		if (NULL == root || NULL == p) return NULL;

		if (root->val <= p->val) {
			return inorderSuccessor(root->right, p);
		}
		else {
			TreeNode * left = inorderSuccessor(root->left, p);
			return NULL == left ? root : left;
		}
	}
};

////iterative traversal
//class Solution {
//public:
//	TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
//		if (NULL == root || NULL == p) return NULL;
//
//		stack<TreeNode *> s;
//		TreeNode * pre = NULL;
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
//			if (pre == p) break;
//			pre = root;
//
//			root = root->right;
//		}
//
//		return root;
//	}
//};