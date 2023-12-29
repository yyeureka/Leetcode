#include "head.h"

/*
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.

For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:
3
/ \
9  20
/  \
15   7

解题思路：与#105非常类似，区别在postorder的root node从末尾开始，接下来依次为右node，再左node
*/

class Solution {
public:
	TreeNode * helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postEnd) {
		if (inStart > inEnd) return NULL;

		TreeNode * node = new TreeNode(postorder[postEnd]);
		if (inStart == inEnd) return node;

		int i;
		for (i = inStart; i <= inEnd; i++) {
			if (inorder[i] == postorder[postEnd]) break;
		}
		//极易错
		node->left = helper(inorder, inStart, i - 1, postorder, postEnd - 1 - (inEnd - i));
		node->right = helper(inorder, i + 1, inEnd, postorder, postEnd - 1);

		return node;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty()) return NULL; //易错

		return helper(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
	}
};