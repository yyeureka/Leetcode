#include "head.h"

/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example1
Input:
{4, 3, 7, #, #, 5, 6}
3 5
5 6
6 7
5 8
Output:
4
7
7
null
Explanation:
4
/ \
3   7
/ \
5   6
LCA(3, 5) = 4
LCA(5, 6) = 7
LCA(6, 7) = 7
LCA(5, 8) = null
Example2
Input:
{1}
1 1
Output:
1
Explanation:
The tree is just a node, whose value is 1.

Notice
node A or node B may not exist in tree.
Each node has a different value

解题思路：类似#236，但要处理node不一定在BT中的情况
*/

class Solution {
private:
	class Result {
	public:
		bool findA; //A是否找到
		bool findB;
		TreeNode * lca;

		Result(bool a, bool b, TreeNode * lca) {
			this->findA = a;
			this->findB = b;
			this->lca = lca;
		}
	};
public:
	TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
		if (NULL == root) return NULL;

		Result * res = helper(root, A, B);

		if (res->findA && res->findB) return res->lca;
		return NULL;
	}

	Result * helper(TreeNode * root, TreeNode * A, TreeNode * B) {
		if (NULL == root) return new Result(false, false, NULL);

		Result * left = helper(root->left, A, B);
		Result * right = helper(root->right, A, B);

		bool a = left->findA || right->findA || root == A; //关键点
		bool b = left->findB || right->findB || root == B;

		if (root == A || root == B) return new Result(a, b, root);
		if (left->lca && right->lca) return new Result(a, b, root);
		if (left->lca) return new Result(a, b, left->lca);
		if (right->lca) return new Result(a, b, right->lca);
		return new Result(a, b, NULL);
	}
};