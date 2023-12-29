#include "head.h"

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:
Input：{1,#,2},2
Output：2
Explanation：
1
\
2
The second smallest element is 2.
Example 2:
Input：{2,1,3},1
Output：1
Explanation：
2
/ \
1   3
The first smallest element is 1.

Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Notice
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

解题思路：
1、iterative traversal，O(h+k)时间
2、recursive traversal，O(n)时间

challenge优化方法：
记录每个节点为root的subtree的节点个数，增删查找时维护这个值
利用类似quick select的方法找kth
时间O(n)
*/

//iterative traversal
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		vector<TreeNode*> v;

		while (root || !v.empty()) {
			while (root) {
				v.push_back(root);
				root = root->left;
			}

			root = v.back();
			v.pop_back();
			if (0 == --k) break;

			root = root->right;
		}
		return root->val;
	}
};

////quick select
//class Solution {
//public:
//	unordered_map<TreeNode *, int> nodeNum;
//
//	int kthSmallest(TreeNode * root, int k) {
//		if (NULL == root) return -1;
//
//		countNode(root);
//
//		return findKth(root, k);
//	}
//
//	int countNode(TreeNode * root) {
//		if (NULL == root) return 0;
//
//		int num = countNode(root->left) + countNode(root->right) + 1;
//		nodeNum.insert({ root, num });
//
//		return num;
//	}
//
//	int findKth(TreeNode * root, int k) {
//		int leftNodeNum = 0;
//		if (root->left) leftNodeNum = nodeNum[root->left];
//		if (leftNodeNum >= k) return findKth(root->left, k); //>=易错
//
//		if (k == leftNodeNum + 1) return root->val;
//
//		if (root->right) return findKth(root->right, k - leftNodeNum - 1); //易错，要修改k的值
//	}
//};

////recursive traversal
//class Solution {
//public:
//	int kthSmallest(TreeNode* root, int k) {
//		int res;
//
//		dfs(root, k, res);
//
//		return res;
//	}
//private:
//	void dfs(TreeNode* node, int &k, int &res) { //易错 k和res的&
//		if (NULL == node) return;
//
//		dfs(node->left, k, res);
//
//		if (0 == --k) {
//			res = node->val;
//			return;
//		}
//
//		dfs(node->right, k, res);
//	}
//};