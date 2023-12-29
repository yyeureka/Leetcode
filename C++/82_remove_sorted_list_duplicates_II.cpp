#include <list>
using namespace std;

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:
Input: 1->1->1->2->3
Output: 2->3

1、类似83，需增加一个pre指针从head前开始，每当元素重复时，删掉重复后，用pre删掉元素本身
2、recursive
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* pre = start;
		int flag = false;
		while (head && head->next) {
			if (head->val == head->next->val) {
				while (head && head->next && head->val == head->next->val) {
					head->next = head->next->next;
				}
				pre->next = pre->next->next;
				head = pre->next;
			}
			else {
				pre = head;
				head = head->next;
			}
		}
		return start->next;
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
//			return deleteDuplicates(head->next);  //与#83的区别
//		}
//		else {
//			head->next = deleteDuplicates(head->next);
//			return head;
//		}
//	}
//};