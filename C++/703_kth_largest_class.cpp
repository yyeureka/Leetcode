#include <vector>
#include <queue>
#include <xfunctional>
using namespace std;

/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.

Example:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8

解题思路：min priority queue，pq的大小最大为k，pq.top()永远为目标值
易错点：一开始的nums可能为空，add第一个数的时候.top()可能为null
*/

class KthLargest {
public:
	int size;
	priority_queue<int, vector<int>, greater<int>> pq;

	KthLargest(int k, vector<int>& nums) {
		size = k;
		for (int i : nums) {
			pq.push(i);
			if (pq.size() > size) pq.pop();
		}
	}

	int add(int val) {
		if (pq.size() < size) pq.push(val);
		else if (val > pq.top()) {
			pq.push(val);
			pq.pop();
		}
		return pq.top();
	}
};