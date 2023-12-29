#include <iostream>

/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.

Example1
Input: 1 -> 2 -> 3 -> null
Output: 1 -> 2 -> 4 -> null
Explanation:
123 + 1 = 124
Example2
Input: 9 -> 9 -> null
Output: 1 -> 0 -> 0 -> null
Explanation:
99 + 1 = 100

解题思路：recursive，每个node加上下一个node的进位，最后一个node+1，第一个node是否溢出决定是否在head前增加node
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * plusOne(ListNode * head) {
		if (plus(head) > 0) {
			ListNode * root = new ListNode(1);
			root->next = head;
			return root;
		}
		return head;
	}

	int plus(ListNode * node) {
		if (NULL == node->next) {
			node->val += 1;
		}
		else {
			node->val += plus(node->next);
		}

		if (node->val > 9) {
			node->val -= 10;
			return 1;
		}
		return 0;
	}
};