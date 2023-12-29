#include <list>
using namespace std;

/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
Note:
The number of nodes in the given list will be between 1 and 100.

Example 1:
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

解题思路：fast走两步，slow走一步
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * middleNode(ListNode * head) {
		if (NULL == head) return NULL; //易错

		ListNode * fast = head->next; //两个node，停在第一个，稍微tricky点
		ListNode * slow = head;

		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}
};

////#876稍许不同 更简单
//class Solution {
//public:
//	ListNode* middleNode(ListNode* head) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//
//		while (fast && fast->next) {
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//
//		return slow;
//	}
//};