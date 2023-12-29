#include "head.h"

/*
Given a continuous stream of data, write a function that returns the first unique number (including the last number) when the terminating number arrives. If the unique number is not found, return -1.

Example1
Input:
[1, 2, 2, 1, 3, 4, 4, 5, 6]
5
Output: 3
Example2
Input:
[1, 2, 2, 1, 3, 4, 4, 5, 6]
7
Output: -1
Example3
Input:
[1, 2, 2, 1, 3, 4]
3
Output: 3

����˼·��
1��hashmap+queue��ÿ��һ��������queue��pop������unique��������terminating��ʱ���queue��Ϊ�գ�front()��Ϊ��һ��unique
2��hashmap+linked list������#380������д��ʱ��/�ռ䶼û������
*/

class Solution {
public:
	int firstUniqueNumber(vector<int> &nums, int number) {
		unordered_map<int, int> frequent;
		queue<int> q;

		for (int i : nums) {
			if (frequent[i] > 1) continue;

			if (0 == frequent[i]) {
				q.push(i);
			}
			frequent[i]++;

			while (!q.empty() && frequent[q.front()] > 1) {
				q.pop();
			}

			if (i == number) return q.empty() ? -1 : q.front(); //�״�
		}

		return -1;
	}
};

//class Solution {
//public:
//	class Node {
//	public:
//		int val;
//		Node * next;
//
//		Node(int val) {
//			this->val = val;
//			this->next = NULL;
//		}
//	};
//
//	int firstUniqueNumber(vector<int> &nums, int number) {
//		Node * head = new Node(0);
//		Node * tail = head;
//		unordered_map<int, Node *> getPre;
//		unordered_map<int, int> frequent;
//
//		for (int i : nums) {
//			if (0 == frequent[i]) {
//				getPre[i] = tail;
//				tail->next = new Node(i);
//				tail = tail->next;
//			}
//			else if (1 == frequent[i]) {
//				if (getPre[i]->next->next) {
//					getPre[getPre[i]->next->next->val] = getPre[i];
//					getPre[i]->next = getPre[i]->next->next;
//				}
//				else {
//					getPre[i]->next = NULL;
//					tail = getPre[i];
//				}
//				getPre.erase(i);
//			}
//			frequent[i]++;
//
//			if (i == number) {
//				return head->next ? head->next->val : -1;
//			}
//		}
//
//		return -1;
//	}
//};

