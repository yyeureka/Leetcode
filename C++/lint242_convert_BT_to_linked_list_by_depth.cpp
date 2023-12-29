#include "head.h"

/*
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
Example 1:

Input: {1,2,3,4}
Output: [1->null,2->3->null,4->null]
Explanation:
1
/ \
2   3
/
4

Example 2:
Input: {1,#,2,3}
Output: [1->null,2->null,3->null]
Explanation:
1
\
2
/
3

解题思路:DFS&BFS
*/

//DFS
class Solution {
public:
	void dfs(TreeNode* root, int depth, vector<ListNode*> &res) {
		if (NULL == root) return;

		ListNode* cur = new ListNode(root->val);
		if (depth > res.size()) {
			res.push_back(cur);
		}
		else {
			cur->next = res[depth - 1];
			res[depth - 1] = cur;
		}

		if (root->right) dfs(root->right, depth + 1, res); //linked list的关系需要调换顺序
		if (root->left) dfs(root->left, depth + 1, res);
	}

	vector<ListNode*> binaryTreeToLists(TreeNode* root) {
		if (NULL == root) return{};

		vector<ListNode*> res;
		dfs(root, 1, res);
		return res;
	}
};

////BFS
//class Solution {
//public:
//	vector<ListNode*> binaryTreeToLists(TreeNode* root) {
//		if (NULL == root) return{};
//
//		vector<ListNode*> res;
//		queue<TreeNode*> q;
//		q.push(root);
//		while (!q.empty()) {
//			ListNode* start = new ListNode(0);
//			ListNode* tmp = start;
//
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				TreeNode* cur = q.front();
//				q.pop();
//				if (cur->left) q.push(cur->left);
//				if (cur->right) q.push(cur->right);
//
//				tmp->next = new ListNode(cur->val);
//				tmp = tmp->next;
//			}
//			res.push_back(start->next);
//		}
//		return res;
//	}
//};