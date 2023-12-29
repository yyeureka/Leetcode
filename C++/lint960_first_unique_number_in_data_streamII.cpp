#include "head.h"

/*
We need to implement a data structure named DataStream. There are two methods required to be implemented:

void add(number) // add a new number
int firstUnique() // return first unique number

Example 1:
Input:
add(1)
add(2)
firstUnique()
add(1)
firstUnique()
Output:
[1,2]
Example 2:
Input:
add(1)
add(2)
add(3)
add(4)
add(5)
firstUnique()
add(1)
firstUnique()
add(2)
firstUnique()
add(3)
firstUnique()
add(4)
firstUnique()
add(5)
add(6)
firstUnique()
Output:
[1,2,3,4,5,6]

Notice
You can assume that there must be at least one unique number in the stream when calling the firstUnique.

解题思路：#685异曲同工
*/

class DataStream {
public:
	queue<int> nums;
	unordered_map<int, int> frequent;

	DataStream() {
		// do intialization if necessary
	}

	void add(int num) {
		if (frequent[num] > 1) return;

		if (0 == frequent[num]) {
			nums.push(num);
		}
		frequent[num]++;

		while (!nums.empty() && frequent[nums.front()] > 1) {
			nums.pop();
		}
	}

	int firstUnique() {
		return nums.empty() ? -1 : nums.front();
	}
};

//class DataStream {
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
//	Node * head;
//	Node * tail;
//	unordered_map<int, Node *> getPre;
//	unordered_map<int, int> frequent;
//
//	DataStream() {
//		head = new Node(0);
//		tail = head;
//	}
//
//	void add(int num) {
//		if (0 == frequent[num]) {
//			getPre[num] = tail;
//			tail->next = new Node(num);
//			tail = tail->next;
//		}
//		else if (1 == frequent[num]) {
//			if (getPre[num]->next->next) {
//				getPre[getPre[num]->next->next->val] = getPre[num];
//				getPre[num]->next = getPre[num]->next->next;
//			}
//			else {
//				getPre[num]->next = NULL;
//				tail = getPre[num];
//			}
//			getPre.erase(num);
//		}
//		frequent[num]++;
//	}
//
//	int firstUnique() {
//		return head->next ? head->next->val : -1;
//	}
//};