#include <iostream>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list
You may assume the two numbers do not contain any leading zero, except the number 0 itself
Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode 
{
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0);
		ListNode* tmp = res;
		int carry = 0;
		while (l1 || l2 || carry) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}

			tmp->next = new ListNode(carry % 10);
			tmp = tmp->next;
			carry /= 10;
		}
		return res->next;
	}
};

//不需要额外空间
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		if (NULL == l1) return l2;
//
//		int digit = l1->val;
//		if (l2) {
//			digit += l2->val;
//			l2 = l2->next;
//		}
//
//		if (digit > 9) {
//			if (l1->next) l1->next->val++;
//			else l1->next = new ListNode(1);
//		}
//		l1->val = digit % 10;
//		l1->next = addTwoNumbers(l1->next, l2);
//		return l1;
//	}
//};