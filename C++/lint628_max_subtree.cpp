#include <algorithm>
using namespace std;

/*
Given a binary tree, find the subtree with maximum sum. Return the root of the subtree.
Notes:
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum sum and the given binary tree is not an empty tree.

Example 1:
Input:
{1,-5,2,0,3,-4,-5}
Output:3
Explanation:
The tree is look like this:
1
/   \
-5     2
/ \   /  \
0   3 -4  -5
The sum of subtree 3 (only one node) is the maximum. So we return 3.
Example 2:
Input:
{1}
Output:1
Explanation:
The tree is look like this:
1
There is one and only one subtree in the tree. So we return 1.

解题思路：dfs
使用成员变量ok，但传参会出错，不知道为啥
*/

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
	TreeNode *max_node = NULL;
	int max_sum = INT_MIN;
public:
	int dfs(TreeNode *root) {
		if (NULL == root) return 0;

		int sum = root->val + dfs(root->left) + dfs(root->right);
		if (sum > max_sum) {
			max_sum = sum;
			max_node = root;
		}

		return sum;
	}

	TreeNode * findSubtree(TreeNode * root) {
		dfs(root);
		return max_node;
	}
};