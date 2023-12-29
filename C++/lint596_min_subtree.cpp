#include "head.h"

/*
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example 1:
Input:
{1,-5,2,1,2,-4,-5}
Output:1
Explanation:
The tree is look like this:
1
/   \
-5     2
/ \   /  \
1   2 -4  -5
The sum of whole tree is minimum, so return the root.
Example 2:
Input:
{1}
Output:1
Explanation:
The tree is look like this:
1
There is one and only one subtree in the tree. So we return 1.

Notice
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.
*/

class Solution {
private:
	TreeNode *res = NULL;
	int minSum = INT_MAX;
public:
	int dfs(TreeNode * root) {
		if (NULL == root) return 0;

		int sum = root->val + dfs(root->left) + dfs(root->right);
		if (sum < minSum) {
			minSum = sum;
			res = root;
		}

		return sum;
	}

	TreeNode * findSubtree(TreeNode * root) {
		if (NULL == root) return NULL;

		dfs(root);

		return res;
	}
};

//class Solution {
//private:
//	class Result {
//	public:
//		int sum;
//		int minSum;
//		TreeNode * minNode;
//
//		Result(int sum, int minSum, TreeNode * minNode) {
//			this->sum = sum;
//			this->minSum = minSum;
//			this->minNode = minNode;
//		}
//	};
//public:
//	Result * helper(TreeNode * root) {
//		if (NULL == root) return new Result(0, INT_MAX, NULL);
//
//		Result * left = helper(root->left);
//		Result * right = helper(root->right);
//		int sum = root->val + left->sum + right->sum;
//
//		if (sum < left->minSum && sum < right->minSum) return new Result(sum, sum, root);
//		if (left->minSum < right->minSum) return new Result(sum, left->minSum, left->minNode);
//		return new Result(sum, right->minSum, right->minNode);
//	}
//
//	TreeNode * findSubtree(TreeNode * root) {
//		if (NULL == root) return NULL;
//
//		Result * res = helper(root);
//
//		return res->minNode;
//	}
//};