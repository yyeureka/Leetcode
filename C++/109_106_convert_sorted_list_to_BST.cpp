#include "head.h"

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Example 1:
Input: array = 1->2->3
Output:
2
/ \
1  3
Example 2:
Input: 2->3->6->7
Output:
3
/ \
2   6
\
7

Explanation:
There may be multi answers, and you could return any of them.

解题思路：
1、类似2的思路直接对linked list进行操作
2、将sorted list转化为vector，类似#108
*/

class Solution {
public:
	TreeNode * sortedListToBST(ListNode * head) {
		TreeNode * res;
		int len = getLength(head);

		res = convert(head, len);

		return res;
	}

	int getLength(ListNode * head) {
		int len = 0;

		while (head) {
			len++;
			head = head->next;
		}

		return len;
	}

	TreeNode * convert(ListNode * &head, int len) {
		if (!len) return NULL;

		TreeNode * root;

		if (1 == len) {
			root = new TreeNode(head->val);
			head = head->next; //易错，head需要移
		}
		else {
			TreeNode * left = convert(head, len / 2);

			root = new TreeNode(head->val);
			head = head->next; //易错，head需要移

			root->left = left;
			root->right = convert(head, len - len / 2 - 1); //易错，要减1
		}

		return root;
	}
};

//class Solution {
//public:
//	TreeNode* sortedListToBST(ListNode* head) {
//		TreeNode * res;
//		vector<int> nodes;
//
//		while (head) {
//			nodes.push_back(head->val);
//			head = head->next;
//		}
//
//		res = convert(nodes, 0, nodes.size() - 1);
//
//		return res;
//	}
//
//	TreeNode * convert(vector<int> &node, int start, int end) {
//		if (start > end) return NULL;
//		if (start == end) return new TreeNode(node[start]);
//
//		int mid = start + (end - start) / 2;
//		TreeNode * root = new TreeNode(node[mid]);
//		root->left = convert(node, start, mid - 1);
//		root->right = convert(node, mid + 1, end);
//
//		return root;
//	}
//};