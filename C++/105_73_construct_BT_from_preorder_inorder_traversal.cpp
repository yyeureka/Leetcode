#include "head.h"

/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:
3
/ \
9  20
/  \
15   7

解题思路：
类似#106，preorder中的顶点，在inorder中他左边的为左子树，右边的为右子树，recursive细分
*/

class Solution {
public:
	TreeNode * helper(vector<int> &preorder, int preStart, vector<int> &inorder, int inStart, int inEnd) {
		if (inStart > inEnd) return NULL;

		TreeNode * node = new TreeNode(preorder[preStart]);
		if (inStart == inEnd) return node;

		int i;
		for (i = inStart; i <= inEnd; i++) {
			if (inorder[i] == preorder[preStart]) break;
		}
		//极易错
		node->left = helper(preorder, preStart + 1, inorder, inStart, i - 1);
		node->right = helper(preorder, preStart + 1 + (i - inStart), inorder, i + 1, inEnd);

		return node;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return NULL; //易错

		return helper(preorder, 0, inorder, 0, inorder.size() - 1);
	}
};