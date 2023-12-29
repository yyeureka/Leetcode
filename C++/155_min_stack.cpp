#include <stack>
using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

解题思路：
使用原始stack，push的时候获取min，将曾经的min作为次小值在min前push进去，
当pop出的是min时，min更新为min前的次小值，并把重复push的次小值pop出去
*/

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> s;
	int min;

	MinStack() {
		min = INT_MAX;
	}

	void push(int x) {
		if (x <= min) {  //易错点，相等的时候，min也是次小值
			s.push(min);
			min = x;
		}
		s.push(x);
	}

	void pop() {
		if (min == s.top()) {
			s.pop();
			min = s.top();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min;
	}
};