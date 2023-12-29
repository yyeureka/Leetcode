#include <stack>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

解题思路：
1、两个stack保存两个list的val，再pop出来相加，注意计算出来的node需要reverse
2、不适用buffer待解决！
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0);

		stack<int> s1;
		stack<int> s2;
		while (l1) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			s2.push(l2->val);
			l2 = l2->next;
		}

		int digit = 0;
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty()) {
				digit += s1.top();
				s1.pop();
			}
			if (!s2.empty()) {
				digit += s2.top();
				s2.pop();
			}

			res->val = digit % 10;
			digit /= 10;
			ListNode* head = new ListNode(digit);
			head->next = res;
			res = head;
		}
		return res->val > 0 ? res : res->next;
	}
};