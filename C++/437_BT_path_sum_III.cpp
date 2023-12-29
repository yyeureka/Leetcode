#include <iostream>
using namespace std;

/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
10
/  \
5   -3
/ \    \
3   2   11
/ \   \
3  -2   1
Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

解题思路：
难点：某个path sum达到预期后，不能停止查找！要一直检查到leaf
recursive pre-order traversal，对每一个node，都计算一下以他起始的path
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (NULL == root) return 0;
		return add(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int add(TreeNode* node, int sum) {
		if (NULL == node) return 0;
		int res = 0;
		sum -= node->val;
		if (0 == sum) res = 1; //这里不能return，还得继续加下去！
		return res + add(node->left, sum) + add(node->right, sum);
	}
};