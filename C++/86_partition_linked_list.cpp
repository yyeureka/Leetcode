#include <list>
using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

解题思路：
1、将小的node放进llist，将大的node放进rlist，将rlist接在llist后面。简洁清晰，不容易出错
2、在原list基础上修改，小的从后面删除往前插入
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* left = new ListNode(0);
		ListNode* l = left;
		ListNode* right = new ListNode(0);
		ListNode* r = right;
		while (head) {
			if (head->val >= x) {
				r->next = head;
				r = r->next;
			}
			else {
				l->next = head;
				l = l->next;
			}
			head = head->next;
		}
		r->next = NULL;  //这一句防止出现cycle
		l->next = right->next;
		return left->next;
	}
};

//class Solution {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		ListNode* res = new ListNode(0);
//		res->next = head;
//		ListNode* fast = res;
//		ListNode* slow = NULL;
//		while (fast && fast->next) {
//			if (fast->next->val >= x) {
//				if (NULL == slow) slow = fast;
//				fast = fast->next;
//			}
//			else {
//				if (NULL == slow) fast = fast->next;
//				else {
//					ListNode* tmp = fast->next;
//					fast->next = fast->next->next;
//					tmp->next = slow->next;
//					slow->next = tmp;
//					slow = slow->next;
//				}
//			}
//		}
//		return res->next;
//	}
//};