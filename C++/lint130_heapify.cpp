#include "head.h"

/*
Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

Example 1
Input : [3,2,1,4,5]
Output : [1,2,3,4,5]
Explanation : return any one of the legitimate heap arrays

Challenge
O(n) time complexity

Clarification
What is heap? What is heapify? What if there is a lot of solutions?

Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.
Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].
Return any of them.

解题思路：
1、siftup，O(nlogn)
2、siftdown，O(n)
*/

//sift down
class Solution {
public:
	void heapify(vector<int> &A) {
		for (int i = A.size() - 1; i >= 0; i--) {
			siftDown(A, i);
		}
	}

	void siftDown(vector<int> &A, int index) {
		while (2 * index + 1 < A.size()) {
			int son = 2 * index + 1;
			if (2 * index + 2 < A.size() && A[2 * index + 2] < A[2 * index + 1]) {
				son = 2 * index + 2;
			}

			if (A[index] <= A[son]) {
				break;
			}

			swap(A[index], A[son]);
			index = son;
		}
	}
};

//siftup
//class Solution {
//public:
//	void heapify(vector<int> &A) {
//		for (int i = 0; i < A.size(); i++) {
//			siftUp(A, i);
//		}
//	}
//
//	void siftUp(vector<int> &A, int index) {
//		while (index > 0) {
//			int father = (index - 1) / 2;
//
//			if (A[index] >= A[father]) {
//				break;
//			}
//
//			swap(A[index], A[father]);
//			index = father;
//		}
//	}
//};