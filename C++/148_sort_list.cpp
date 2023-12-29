#include <vector>
#include <algorithm>
using namespace std;

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4
Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5

解题思路：
merge sort，将list分成两半，再将两半排序merge
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) { val = x; next = NULL; }
};

class Solution {
public:
	ListNode* merge(ListNode* left, ListNode* right) {
		if (!left && !right) return NULL;
		if (!left) return right;
		if (!right) return left;

		if (left->val < right->val) {
			left->next = merge(left->next, right);
			return left;
		}
		else {
			right->next = merge(left, right->next);
			return right;
		}

		//ListNode* head = new ListNode(0);
		//ListNode* start = head;
		//while (left && right) {
		//	if (left->val < right->val) {
		//		start->next = left;
		//		left = left->next;
		//	}
		//	else {
		//		start->next = right;
		//		right = right->next;
		//	}
		//	start = start->next;
		//}
		//if (left) start->next = left;
		//if (right) start->next = right;

		//return head->next;
	}

	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head; //head->next这个别忘

		ListNode* slow = head;
		ListNode* fast = head->next; //这样是为了右半部分>=左半部分
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL; //将两半分开防止cycle
		return merge(sortList(head), sortList(fast));
	}
};
