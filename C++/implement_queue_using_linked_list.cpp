#include "head.h"

/*

*/

class myQueue {
private:
	class queueNode {
	public:
		int val;
		queueNode * next;

		queueNode(int val) {
			this->val = val;
			this->next = NULL;
		}
	};

	queueNode * dummy;
	queueNode * tail;
public:
	myQueue() {
		dummy = new queueNode(0);
		tail = dummy;
	}

	void enqueue(int val) {
		tail->next = new queueNode(val);
		tail = tail->next;
	}

	int dequeue() {
		int val = peek();

		if (-1 != val) {
			dummy->next = dummy->next->next;
		}
		else {
			tail = dummy; //易错，reset，这时tail已经被删掉了
		}

		return val;
	}

	int peek() {
		if (!isEmpty()) {
			return dummy->next->val;
		}
		return -1;
	}

	bool isEmpty() {
		return dummy->next == NULL;
	}
};