#include "head.h"

/*
Implement a stack. You can use any data structure inside a stack except stack itself to implement it.

Example 1:
Input:
push(1)
pop()
push(2)
top()  // return 2
pop()
isEmpty() // return true
push(3)
isEmpty() // return false
Example 2:
Input:
isEmpty()

解题思路：
1、直接用vector就好。。。
2、或者用一个queue
*/

class Stack {
	vector<int> myStack;
public:
	void push(int x) {
		myStack.push_back(x);
	}

	void pop() {
		myStack.pop_back();
	}

	int top() {
		return myStack.back();
	}

	bool isEmpty() {
		return myStack.empty();
	}
};