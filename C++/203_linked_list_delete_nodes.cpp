#include <list>
using namespace std;

/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

解题思路：
iterative：
先判断head元素是否需要删除，如需要head = head->next
再判断cur->next元素是否需要删除，如需要cur->next = cur->next->next，如不需要cur = cur->next

recursive
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while (head && val == head->val) head = head->next;
		ListNode* cur = head;

		while (cur && cur->next) {
			if (val == cur->next->val) cur->next = cur->next->next;
			else cur = cur->next;
		}
		return head;
	}
};

//class Solution {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		if (NULL == head) return NULL;
//		head->next = removeElements(head->next, val);
//		return val == head->val ? head->next : head;
//	}
//};