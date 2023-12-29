#include <queue>
#include <algorithm>
using namespace std;

/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.

Example 1:
Input:
2
/ \
2   5
/ \
5   7
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
2
/ \
2   2
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

解题思路：root是最小值，子节点要么相等要么大于root，按曾遍历，找大于root的min
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
		queue<TreeNode*> q;
		if (NULL == root) return -1;
		q.push(root);
		int min_val = root->val;
		int res = INT_MAX;
		int get = false;
		while (!q.empty()) {
			root = q.front();
			q.pop();
			if (root->val > min_val) {
				get = true;
				res = min(res, root->val);
			}
			if (root->left) q.push(root->left);
			if (root->right) q.push(root->right);
		}
		return get ? res : -1;
	}
};