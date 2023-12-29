#include "head.h"

/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller than the given integer.

Example 1:
Input: array =[1,2,7,8,5] queries =[1,8,5]
Output:[0,4,2]
Example 2:
Input: array =[3,4,5,8] queries =[2,4]
Output:[0,1]

Challenge:
Could you use three ways to do it.
Just loop
Sort and binary search
Build Segment Tree and Search.

解题思路：类似lint249
1、binary indexed tree或segment tree
2、sort+binary search
*/

//binary search
class Solution {
public:
	vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
		if (queries.empty()) {
			return{};
		}
		if (A.empty()) {
			return vector<int>(queries.size(), 0);
		}

		vector<int> results;

		sort(A.begin(), A.end());

		for (int i : queries) {
			results.push_back(find_less(A, i));
		}

		return results;
	}

	int find_less(vector<int> &num, int target) {
		int left = 0;
		int right = num.size() - 1;

		while (left + 1 < right) {
			int mid = left + (right - left) / 2;

			if (num[mid] >= target) {
				right = mid;
			}
			else {
				left = mid;
			}
		}

		if (num[right] < target) {
			return right + 1;
		}
		if (num[left] < target) {
			return left + 1;
		}
		return left;
	}
};

//binary indexed tree
//class Solution {
//	class BITree {
//	private:
//		vector<int> tree;
//	public:
//		BITree(int range) {
//			tree = vector<int>(range + 2, 0);
//		}
//
//		void update(int idx, int delta) {
//			idx++;
//			while (idx < tree.size()) {
//				tree[idx] += delta;
//				idx += idx & (-idx);
//			}
//		}
//
//		int prefixSum(int idx) {
//			int sum = 0;
//
//			idx++;
//			while (idx > 0) {
//				sum += tree[idx];
//				idx -= idx & (-idx);
//			}
//
//			return sum;
//		}
//	};
//public:
//	vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
//		if (queries.empty()) {
//			return{};
//		}
//
//		vector<int> results;
//		BITree *tree = new BITree(10000);
//
//		for (int i : A) {
//			tree->update(i, 1);
//		}
//		for (int i : queries) {
//			results.push_back(tree->prefixSum(i - 1));
//		}
//
//		return results;
//	}
//};