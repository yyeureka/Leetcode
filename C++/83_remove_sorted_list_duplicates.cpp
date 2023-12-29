#include <list>
using namespace std;

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2
Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* start = head;
		while (start && start->next) {
			if (start->next->val == start->val) start->next = start->next->next;
			else start = start->next;
		}
		return head;
	}
};

//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		if (NULL == head) return NULL;
//		if (NULL == head->next) return head;
//
//		if (head->val == head->next->val) {
//			while (head->next && head->val == head->next->val) {
//				head = head->next;
//			}
//		}
//		head->next = deleteDuplicates(head->next);  //与#82的区别
//		return head;
//	}
//};