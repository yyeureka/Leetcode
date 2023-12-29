#include <list>
using namespace std;

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

解题思路：
1、先找确定存在cycle
2、when meet，slow走了k步，fast走了2k步，2k-k=nr，k=nr
   从start到cycle begin的距离为s，cycle begin到meet point为m=k-s，s=nr-m=(n-1)r+(r-m)
   slow从start出发，fast从meet point出发，meet的时候即为cycle begin
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;

		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) {
				slow = head;

				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}

				return slow;
			}
		}

		return NULL;
	}
};
