#include "head.h"

/*
Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

Example 1
Input:
L = [232, 124, 456]
k = 7
Output: 114
Explanation: We can cut it into 7 pieces if any piece is 114cm long, however we can't cut it into 7 pieces if any piece is 115cm long.
Example 2
Input:
L = [1, 2, 3]
k = 7
Output: 0
Explanation: It is obvious we can't make it.

Challenge
O(n log Len), where Len is the longest length of the wood.

Notice
You couldn't cut wood into float length.
If you couldn't get >= k pieces, return 0.

解题思路：bs最长那段木头，找到count(mid) == k, count(mid + 1) < k的那个mid
*/

class Solution {
public:
	int count(vector<int> &L, int len) {
		int count = 0;

		for (int i : L) count += i / len;

		return count;
	}

	int woodCut(vector<int> &L, int k) {
		if (L.empty()) return 0;

		int start = 1;
		int end = L[0];

		for (int i = 1; i < L.size(); i++) { //不要sort，sort是nlogn的
			if (L[i] > end) end = L[i];
		}

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int num = count(L, mid);

			if (num >= k) start = mid;
			else end = mid;
		}

		if (count(L, end) >= k) return end;
		if (count(L, start) >= k) return start;
		return 0;
	}
};

//class Solution {
//public:
//	int count(vector<int> &L, int len) {
//		int count = 0;
//
//		for (int i : L) count += i / len;
//
//		return count;
//	}
//
//	int woodCut(vector<int> &L, int k) {
//		if (L.empty()) return 0;
//
//		int res = 0;
//		int start = 1;
//		int end = L.back();
//
//		for (int i = 1; i < L.size(); i++) {
//			if (L[i] > end) end = L[i];
//		}
//
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			int num = count(L, mid);
//
//			if (num >= k) {
//				res = mid;
//				start = mid + 1;
//			}
//			else end = mid - 1;
//		}
//
//		return res;
//	}
//};

//class Solution {
//public:
//	int count(vector<int> &L, int len) {
//		int count = 0;
//
//		for (int i : L) count += i / len;
//
//		return count;
//	}
//
//	int woodCut(vector<int> &L, int k) {
//		if (L.empty()) return 0;
//
//		sort(L.begin(), L.end());
//		int start = 1;
//		int end = L.back();
//
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			int num = count(L, mid);
//
//			if (num >= k) { //易错，==k的时候不能直接return，需要检查mid+1
//				if (count(L, mid + 1) < k) return mid; //这里效率有点低
//				else start = mid + 1;
//			}
//			else end = mid - 1;
//		}
//
//		return 0;
//	}
//};