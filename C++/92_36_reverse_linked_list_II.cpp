#include <list>
using namespace std;

/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

解题思路：
从head前开始，找到m前的元素pre，第一个待翻转的元素cur，每次把cur后的元素删除并放到pre后
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseBetween(ListNode * head, int m, int n) {
		ListNode * pre = NULL;
		ListNode * tail = head;

		for (int i = 1; i < m; i++) {
			pre = tail;
			tail = tail->next;
		}

		ListNode * slow = pre;
		ListNode * fast = tail;
		for (int i = m; i <= n; i++) {
			ListNode * tmp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = tmp;
		}

		if (pre) {
			pre->next = slow;
		}
		else { //易错
			head = slow;
		}
		tail->next = fast;

		return head;
	}
};

//class Solution {
//public:
//	ListNode * reverseBetween(ListNode * head, int m, int n) {
//		ListNode * root = new ListNode(0);
//		root->next = head;
//		ListNode * slow = root;
//		ListNode * fast = head;
//
//		for (int i = 1; i < m; i++) {
//			slow = slow->next;
//			fast = fast->next;
//		}
//
//		for (int i = m; i < n; i++) {
//			ListNode * tmp = fast->next;
//			fast->next = fast->next->next;
//			tmp->next = slow->next;
//			slow->next = tmp;
//		}
//
//		return root->next;
//	}
//};