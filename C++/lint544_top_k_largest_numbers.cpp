#include "head.h"

/*
Given an integer array, find the top k largest numbers in it.

Example1
Input: [3, 10, 1000, -99, 4, 100] and k = 3
Output: [1000, 100, 10]
Example2
Input: [8, 7, 6, 5, 4, 3, 2, 1] and k = 5
Output: [8, 7, 6, 5, 4]

����˼·��
#545 offline programming�汾
ע�� ���ظ����֣�Ҫ��multiset
*/

// Multiset
class Solution {
public:
	vector<int> topk(vector<int> &nums, int k) {
		multiset<int, greater<int>> minHeap;
		for (int i : nums) {
			minHeap.insert(i);

			if (minHeap.size() > k) {
				minHeap.erase(--minHeap.end());
			}
		}

		vector<int> res;
		for (int i : minHeap) {
			res.push_back(i);
		}

		return res;
	}
};

////priority_queue
//class Solution {
//public:
//	vector<int> topk(vector<int> &nums, int k) {
//		priority_queue<int, vector<int>, greater<int>> minHeap;
//		for (int i : nums) {
//			minHeap.push(i);
//
//			if (minHeap.size() > k) {
//				minHeap.pop();
//			}
//		}
//
//		vector<int> res;
//		while (!minHeap.empty()) {
//			res.push_back(minHeap.top());
//			minHeap.pop();
//		}
//
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};