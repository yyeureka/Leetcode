#include <list>
using namespace std;

/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?

Example 1:
Input: 1->2
Output: false
Example 2:
Input: 1->2->2->1
Output: true

解题思路：fast走两步，slow走一步，同时反转前半部分，最后比较前后两半，注意奇偶的处理
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = NULL;
		while (fast && fast->next) {
			fast = fast->next->next;

			ListNode* tmp = head->next;
			head->next = slow;
			slow = head;
			head = tmp;
		}

		if (NULL == fast) fast = head; //even
		else fast = head->next; //odd
		while (slow) {
			if (slow->val != fast->val) return false;
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}
};