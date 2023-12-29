#include <stddef.h>
using namespace std;

/*
Given a linked list, remove the n-th node from the end of list and return its head.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

解题思路：
定义两个node指针fast和slow，fast先走、slow后走，fast到null的时候，slow即到要删除的位置
slow->next = slow->next->next
要注意各种特殊情况
1、slow next是最后一个，slow->next = null
2、删除第一个，head = head->next
*/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* root = new ListNode(0);
		root->next = head;

		ListNode* fast = head;
		ListNode* slow = root;
		while (fast) {
			fast = fast->next;
			if (n > 0) n--;
			else slow = slow->next;
		}

		if (slow->next) slow->next = slow->next->next;

		return root->next;
	}
};