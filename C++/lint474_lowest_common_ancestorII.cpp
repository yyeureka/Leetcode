#include "head.h"

/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Example 1:
Input：{4,3,7,#,#,5,6},3,5
Output：4
Explanation：
4
/ \
3   7
/ \
5   6
LCA(3, 5) = 4
Example 2:
Input：{4,3,7,#,#,5,6},5,6
Output：7
Explanation：
4
/ \
3   7
/ \
5   6
LCA(5, 6) = 7

解题思路：
2、类似#236
*/

class ParentTreeNode {
public:
	int val;
	ParentTreeNode *parent, *left, *right;
};

class Solution {
public:
	/*
	* @param root: The root of the tree
	* @param A: node in the tree
	* @param B: node in the tree
	* @return: The lowest common ancestor of A and B
	*/
	vector<ParentTreeNode *> getPath(ParentTreeNode * node) {
		vector<ParentTreeNode *> res;

		while (node) {
			res.push_back(node);
			node = node->parent;
		}

		return res;
	}

	ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
		if (NULL == root) return NULL;

		vector<ParentTreeNode *> pathA = getPath(A);
		vector<ParentTreeNode *> pathB = getPath(B);

		int i = pathA.size() - 1;
		int j = pathB.size() - 1;
		ParentTreeNode * lca = NULL;

		while (i >= 0 && j >= 0) {
			if (pathA[i] != pathB[j]) break;

			lca = pathA[i];
			i--;
			j--;
		}

		return lca;
	}
};

//class Solution {
//public:
//	ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
//		if (NULL == root) return NULL;
//
//		if (A == root || B == root) return root;
//
//		ParentTreeNode * left = lowestCommonAncestorII(root->left, A, B);
//		ParentTreeNode * right = lowestCommonAncestorII(root->right, A, B);
//
//		if (left && right) return root;
//		else if (left) return left;
//		else if (right) return right;
//		else return NULL;
//	}
//};