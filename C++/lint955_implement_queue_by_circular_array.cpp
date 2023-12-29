#include "head.h"

/*
Implement queue by circulant array. You need to support the following methods:
CircularQueue(n): initialize a circular array with size n to store elements
boolean isFull(): return true if the array is full
boolean isEmpty(): return true if there is no element in the array
void enqueue(element): add an element to the queue
int dequeue(): pop an element from the queue

Example 1:
Input:
CircularQueue(5)
isFull()
isEmpty()
enqueue(1)
enqueue(2)
dequeue()
Output:
["false","true","1"]
Example 2:
Input:
CircularQueue(5)
isFull()
isEmpty()
enqueue(1)
enqueue(2)
dequeue()
dequeue()
enqueue(1)
enqueue(2)
enqueue(3)
enqueue(4)
enqueue(5)
isFull()
dequeue()
dequeue()
dequeue()
dequeue()
dequeue()
Output:
["false","true","1","2","true","1","2","3","4","5"]

Notice
it's guaranteed in the test cases we won't call enqueue if it's full and we also won't call dequeue if it's empty. So it's ok to raise exception in scenarios described above.
*/

class CircularQueue {
private:
	vector<int> circularArray;
	int front;
	int tail;
	int size;
public:
	/**
	* @return:  return true if the array is full
	*/
	CircularQueue(int n) {
		circularArray = vector<int>(n);
		front = 0;
		tail = 0;
		size = 0;
	}

	bool isFull() {
		return size == circularArray.size();
	}

	/**
	* @return: return true if there is no element in the array
	*/
	bool isEmpty() {
		return 0 == size;
	}

	/**
	* @param element: the element given to be added
	* @return: nothing
	*/
	void enqueue(int element) {
		if (isFull()) {
			return;
		}

		circularArray[tail] = element;
		tail = next(tail);
		size++;
	}

	/**
	* @return: pop an element from the queue
	*/
	int dequeue() {
		if (isEmpty()) {
			return -1;
		}

		int val = circularArray[front];
		front = next(front);
		size--;

		return val;
	}

	int next(int pointer) {
		return (pointer + 1) % circularArray.size();
	}
};