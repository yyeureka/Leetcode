#include <list>
using namespace std;

/*
Reverse a singly linked list.
Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

解题思路：incursive/recursive
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverse(ListNode * head) {
		ListNode * result = NULL;

		while (head) {
			ListNode * tmp = head->next;
			head->next = result;
			result = head;
			head = tmp;
		}

		return result;
	}
};

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (NULL == head || NULL == head->next) return head;
//
//		ListNode* tmp = reverseList(head->next);
//		head->next->next = head;
//		head->next = NULL;
//		return tmp;
//	}
//};