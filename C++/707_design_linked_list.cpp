#include <list>
using namespace std;

/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
Implement these functions in your linked list class:
get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Note:
All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.

Example:
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3

解题思路：成员变量node* head、node* tail、int size
*/

class MyLinkedList {
private:
	struct Node {
		int val;
		Node* next;
		Node(int x) : val(x), next(NULL) {}
	};

	Node* head;
	Node* tail;
	int size;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = new Node(0);
		tail = new Node(0);
		head->next = tail;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= size) return -1;
		Node* cur = head;
		while (index-- >= 0) cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		head->val = val;
		Node* tmp = new Node(0);
		tmp->next = head;
		head = tmp;
		size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		tail->val = val;
		tail->next = new Node(0);
		tail = tail->next;
		size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > size) return;
		else if (index <= 0) addAtHead(val);  //test case有问题，可以add负index，但不能删除负index
		else if (size == index) addAtTail(val);
		else {
			Node* cur = head;
			while (index-- > 0) cur = cur->next;
			Node* tmp = new Node(val);
			tmp->next = cur->next;
			cur->next = tmp;
			size++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= size) return;
		Node* cur = head;
		while (index-- > 0) cur = cur->next;
		cur->next = cur->next->next;
		size--;
	}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/