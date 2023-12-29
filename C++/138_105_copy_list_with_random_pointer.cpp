#include <iostream>
using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
Note:
You must return the copy of the given head as a reference to the cloned list.

Example 1:
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

解题思路：
1、hashmap，暴力往next一直走
2、hashmap+queue，跟#133异曲同工
3、challenge,O(1)space:
   循环第一遍，在每个node后面复制一个node
   循环第二遍，给复制的node设好random
   循环第三遍，将复制的node拆出来return
*/

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (NULL == head) return NULL;

		copyNode(head);
		copyRandom(head);

		RandomListNode * copy = head->next;

		while (head) { //这里面极容易错
			RandomListNode * tmp = head->next->next;
			if (tmp) {
				head->next->next = tmp->next;
			}
			head->next = tmp;
			head = tmp;
		}

		return copy;
	}

	void copyNode(RandomListNode *head) {
		while (head) {
			RandomListNode * next = head->next;
			head->next = new RandomListNode(head->label);
			head->next->next = next;
			head = next;
		}
	}

	void copyRandom(RandomListNode *head) {
		while (head) {
			if (head->random) {
				head->next->random = head->random->next;
			}

			head = head->next->next;
		}
	}
};

//class Solution {
//public:
//	RandomListNode *copyRandomList(RandomListNode *head) {
//		unordered_map<RandomListNode *, RandomListNode *> clone;
//
//		RandomListNode * start = head;
//		while (start) {
//			if (NULL == clone[start]) {
//				clone[start] = new RandomListNode(start->label);
//			}
//
//			if (start->random && NULL == clone[start->random]) {
//				clone[start->random] = new RandomListNode(start->random->label);
//			}
//			clone[start]->random = clone[start->random];
//
//			if (start->next && NULL == clone[start->next]) {
//				clone[start->next] = new RandomListNode(start->next->label);
//			}
//			clone[start]->next = clone[start->next];
//
//			start = start->next;
//		}
//
//		return clone[head];
//	}
//};

//class Solution {
//public:
//	RandomListNode *copyRandomList(RandomListNode *head) {
//		if (NULL == head) return NULL;
//
//		unordered_map<RandomListNode *, RandomListNode *> clone;
//		clone[head] = new RandomListNode(head->label);
//		queue<RandomListNode *> todo;
//		todo.push(head);
//
//		while (!todo.empty()) {
//			RandomListNode * node = todo.front();
//			todo.pop();
//
//			if (node->next && NULL == clone[node->next]) {
//				clone[node->next] = new RandomListNode(node->next->label);
//				todo.push(node->next);
//			}
//			clone[node]->next = clone[node->next];
//
//			if (node->random && NULL == clone[node->random]) {
//				clone[node->random] = new RandomListNode(node->random->label);
//				todo.push(node->random);
//			}
//			clone[node]->random = clone[node->random];
//		}
//
//		return clone[head];
//	}
//};