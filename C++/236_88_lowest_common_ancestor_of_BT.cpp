#include <iostream>
using namespace std;

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

解题思路：
如果q、p不能保证都在这个BT中，这个方法不适用
是整个node相等，而不只是val相等
recursive左、右node找p、q：
如root为NULL，返回NULL
如root与p/q相等，返回p/q
如left/right都为NULL，返回NULL
如left/right一个为NULL，返回另一个，也能cover p、q一个是另一个子节点的情况
如left/right都不为NULL，表示p、q在root两边，返回root
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (NULL == root) return NULL;

		if (p == root || q == root) return root;  // 是整个node要相等

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right) return root;
		else if (left) return left;
		else if (right) return right;
		else return NULL;
	}
};