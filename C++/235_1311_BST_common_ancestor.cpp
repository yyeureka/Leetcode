#include <iostream>
using namespace std;

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

解题思路：如果q、p比root小，check root->left，如果q、p比root大，check root->right，否则返回root
recursive，iterative
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive1
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (NULL == root) return NULL;

		if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
		if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};

////recursive2
//class Solution {
//public:
//	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
//		if (NULL == root) return NULL;
//
//		if (p->val > q->val) swap(p, q);
//
//		if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
//		if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
//		return root;
//	}
//};

////iteration
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		while (root) {
//			if (root->val > p->val && root->val > q->val) root = root->left;
//			else if (root->val < p->val && root->val < q->val) root = root->right;
//			else return root;
//		}
//
//		return NULL;
//	}
//};

