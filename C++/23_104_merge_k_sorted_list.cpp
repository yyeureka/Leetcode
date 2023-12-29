#include "head.h"

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
1->4->5,
1->3->4,
2->6
]
Output: 1->1->2->3->4->4->5->6

解题思路：
1、merge sort思想解决，类似rainbow sort那一题，O(nlogk)
2、分别两两merge，结果再两两merge，最终合为1个，每个node参与logk次合并，O(nlogk)
3、priority_queue，将每个list的第一个node加进去，pop出一个加一个next，heap size为k，O(nlogk)
4、暴力多次使用merge2个链表的操作，O(n*k)
*/

//merge sort
class Solution {
public:
	ListNode * mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty()) return NULL;

		return mergeSort(lists, 0, lists.size() - 1);
	}

	ListNode * mergeSort(vector<ListNode *> &lists, int start, int end) {
		if (start == end) {
			return lists[start];
		}

		int mid = (start + end) / 2;
		ListNode * left = mergeSort(lists, start, mid);
		ListNode * right = mergeSort(lists, mid + 1, end);

		return merge2Lists(left, right);
	}

	ListNode * merge2Lists(ListNode * a, ListNode * b) {
		if (NULL == a) return b;
		if (NULL == b) return a;

		if (a->val > b->val) {
			b->next = merge2Lists(a, b->next);
			return b;
		}
		else {
			a->next = merge2Lists(a->next, b);
			return a;
		}
	}
};

//priority_queue
//class Solution {
//public:
//	struct cmp {
//		bool operator()(ListNode * a, ListNode * b) {
//			return a->val > b->val;
//		}
//	};
//
//	ListNode *mergeKLists(vector<ListNode *> &lists) {
//		priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
//
//		for (auto i : lists) {
//			if (i) { //易错，有直接是NULL的list
//				pq.push(i);
//			}
//		}
//
//		ListNode * root = new ListNode(0);
//		ListNode * start = root;
//
//		while (!pq.empty()) {
//			ListNode * node = pq.top();
//			pq.pop();
//
//			if (node->next) {
//				pq.push(node->next);
//			}
//
//			node->next = NULL; //防止cycle
//			start->next = node;
//			start = start->next;
//		}
//
//		return root->next;
//	}
//};

//bottom up
//class Solution {
//public:
//	ListNode * mergeKLists(vector<ListNode *> &lists) {
//		int size = lists.size();
//		while (size > 1) {
//			for (int i = 0; i < size; i += 2) {
//				if (i + 1 >= size) {
//					lists[i / 2] = merge2Lists(lists[i], NULL);
//				}
//				else {
//					lists[i / 2] = merge2Lists(lists[i], lists[i + 1]);
//				}
//			}
//
//			size = (size + 1) / 2;
//		}
//
//		return lists[0];
//	}
//
//	ListNode * merge2Lists(ListNode * a, ListNode * b) {
//		if (NULL == a) return b;
//		if (NULL == b) return a;
//
//		if (a->val > b->val) {
//			b->next = merge2Lists(a, b->next);
//			return b;
//		}
//		else {
//			a->next = merge2Lists(a->next, b);
//			return a;
//		}
//	}
//};


//ListNode* merge2Lists(ListNode* l1, ListNode* l2)
//{
//	if (!l1 && !l2)
//	{
//		return NULL;
//	}
//	else if (!l1)
//	{
//		return l2;
//	}
//	else if (!l2)
//	{
//		return l1;
//	}
//
//	if (l1->val < l2->val)
//	{
//		l1->next = merge2Lists(l1->next, l2);
//		return l1;
//	}
//	else
//	{
//		l2->next = merge2Lists(l1, l2->next);
//		return l2;
//	}
//}
//
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.empty()) return NULL;
//		ListNode* res = lists[0];
//
//		for (int i = 1; i < lists.size(); i++)
//		{
//			res = merge2Lists(res, lists[i]);
//		}
//
//		return res;
//	}
//};