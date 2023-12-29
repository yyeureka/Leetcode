#include "head.h"

/*
Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

Example 1
Input：
{1,-5,11,1,2,4,-2}
Output：11
Explanation:
The tree is look like this:
1
/   \
-5     11
/ \   /  \
1   2 4    -2
The average of subtree of 11 is 4.3333, is the maximun.
Example 2
Input：
{1,-5,11}
Output：11
Explanation:
1
/   \
-5     11
The average of subtree of 1,-5,11 is 2.333,-5,11. So the subtree of 11 is the maximun.

Notice
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum average.

解题思路：类似lint628，helper需要返回num和sum
*/

class Solution {
private:
	class Result {
	public:
		int num;
		int sum;
		double maxAve;
		TreeNode * maxNode;

		Result(int num, int sum, double maxAve, TreeNode * maxNode) {
			this->num = num;
			this->sum = sum;
			this->maxAve = maxAve;
			this->maxNode = maxNode;
		}
	};
public:
	TreeNode * findSubtree2(TreeNode * root) {
		if (NULL == root) return NULL;

		Result * res = helper(root);

		return res->maxNode;
	}

	Result * helper(TreeNode * root) {
		if (NULL == root) return new Result(0, 0, INT_MIN, NULL);

		Result * left = helper(root->left);
		Result * right = helper(root->right);

		int num = 1;
		int sum = root->val;
		num += left->num + right->num;
		sum += left->sum + right->sum;
		double ave = (double)sum / num;

		if (ave > left->maxAve && ave > right->maxAve) return new Result(num, sum, ave, root);
		if (left->maxAve > right->maxAve) return new Result(num, sum, left->maxAve, left->maxNode);
		return new Result(num, sum, right->maxAve, right->maxNode);
	}
};