#include "head.h"

/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]
1
/ \
2   3
Output: 6
Example 2:
Input: [-10,9,20,null,null,15,7]
-10
/ \
9  20
/  \
15   7
Output: 42

解题思路：
注意！不是从上到下的一条path，而是parent-child关系，能一条直线连接的path
recursive pre-order traversal：
对每一个node，node、node+左子树、node+右子树、node+左子树+右子树最大值，更新res
返回node、node+左子树、node+右子树最大值，注意！这里只能选一条子树！
*/

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (NULL == root) return 0;

		int res = INT_MIN;

		dfs(root, res);

		return res;
	}

	int dfs(TreeNode* node, int &res) {
		if (NULL == node) return 0;

		int left = max(0, dfs(node->left, res));  //挺聪明
		int right = max(0, dfs(node->right, res));

		res = max(res, node->val + left + right);

		return node->val + max(left, right);  //这里只能选择一条支路
	}
};