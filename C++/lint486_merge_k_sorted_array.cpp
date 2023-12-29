#include "head.h"

/*
Given k sorted integer arrays, merge them into one sorted array.

Example 1:
Input:
[
[1, 3, 5, 7],
[2, 4, 6],
[0, 8, 9, 10, 11]
]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Example 2:
Input:
[
[1,2,3],
[1,2]
]
Output: [1,1,2,2,3]

Challenge
Do it in O(N log k).
N is the total number of integers.
k is the number of arrays.

解题思路：类似#23
1、priority_queue
2、merge sort
*/

class Solution {
public:
	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
		if (arrays.empty()) return{};

		return mergeSort(arrays, 0, arrays.size() - 1);
	}

	vector<int> mergeSort(vector<vector<int>> &arrays, int start, int end) {
		if (start == end) {
			return arrays[start];
		}

		int mid = (start + end) / 2;
		vector<int> left = mergeSort(arrays, start, mid);
		vector<int> right = mergeSort(arrays, mid + 1, end);

		int i = 0;
		int j = 0;
		vector<int> result;

		while (i < left.size() || j < right.size()) {
			if (i >= left.size()) {
				result.push_back(right[j++]);
			}
			else if (j >= right.size()) {
				result.push_back(left[i++]);
			}
			else if (left[i] > right[j]) {
				result.push_back(right[j++]);
			}
			else {
				result.push_back(left[i++]);
			}
		}

		return result;
	}
};

//class Solution {
//public:
//	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
//		if (arrays.empty()) return{};
//
//		mergeSort(arrays, 0, arrays.size() - 1);
//
//		return arrays[0];
//	}
//
//	void mergeSort(vector<vector<int>> &arrays, int start, int end) {
//		if (start == end) {
//			return;
//		}
//
//		int mid = (start + end) / 2;
//		mergeSort(arrays, start, mid);
//		mergeSort(arrays, mid + 1, end);
//
//		int i = 0;
//		int j = 0;
//		vector<int> tmp;
//
//		while (i < arrays[start].size() || j < arrays[mid + 1].size()) {
//			if (i >= arrays[start].size()) {
//				tmp.push_back(arrays[mid + 1][j++]);
//			}
//			else if (j >= arrays[mid + 1].size()) {
//				tmp.push_back(arrays[start][i++]);
//			}
//			else if (arrays[start][i] > arrays[mid + 1][j]) {
//				tmp.push_back(arrays[mid + 1][j++]);
//			}
//			else {
//				tmp.push_back(arrays[start][i++]);
//			}
//		}
//
//		arrays[start].clear();
//		for (int i : tmp) {
//			arrays[start].push_back(i);
//		}
//	}
//};

//class Solution {
//public:
//	class Element {
//	public:
//		int row;
//		int col;
//		int val;
//
//		Element(int row, int col, int val) {
//			this->row = row;
//			this->col = col;
//			this->val = val;
//		}
//	};
//
//	struct cmp {
//		bool operator()(Element * a, Element * b) {
//			return a->val > b->val;
//		}
//	};
//
//	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
//		if (arrays.empty()) return{};
//
//		priority_queue<Element *, vector<Element *>, cmp> pq;
//		for (int i = 0; i < arrays.size(); i++) {
//			if (!arrays[i].empty()) { //易错
//				pq.push(new Element(i, 0, arrays[i][0]));
//			}
//		}
//
//		vector<int> result;
//		while (!pq.empty()) {
//			int row = pq.top()->row;
//			int col = pq.top()->col;
//			result.push_back(pq.top()->val);
//			pq.pop();
//
//			if (col + 1 < arrays[row].size()) {
//				pq.push(new Element(row, col + 1, arrays[row][col + 1]));
//			}
//		}
//
//		return result;
//	}
//};