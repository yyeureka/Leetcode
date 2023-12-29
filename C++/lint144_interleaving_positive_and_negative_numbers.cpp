#include "head.h"

/*
Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.

Example 1
Input : [-1, -2, -3, 4, 5, 6]
Outout : [-1, 5, -2, 4, -3, 6]
Explanation :  any other reasonable answer.

Challenge
Do it in-place and without extra memory.

Notice
You are not necessary to keep the original order of positive integers or negative integers.

解题思路：
1、partition了正负数以后同向双指针swap
   哪种数多放后面——正数比负数多时，先负后正，否则先正后负
   假如A比B多，以A B A B A A A...这样的顺序interleave
   B B B A A A A A
       l     r
   B B B B A A A A A A
       l         r  
   l和r swap以后分别-2 直到l<0
2、暴力方法，正/负数分别保存进数组，从个数多的那个开始依次加进数组A
*/

class Solution {
public:
	void rerange(vector<int> &A) {
		int positive = 0;
		int negative = 0;

		for (int i : A) {
			if (i > 0) positive++;
			else negative++;
		}

		int left;
		int right;

		if (positive > negative) right = partition(A, false);
		else right = partition(A, true);
		if (right & 1) left = right - 1;
		else left = right - 2;
		right = right * 2 - 1;

		while (left >= 0) {
			swap(A[left], A[right]);
			right -= 2;
			left -= 2;
		}
	}

	int partition(vector<int> &A, bool posFirst) {
		int i = 0;
		int j = A.size() - 1;

		while (i <= j) {
			while (i <= j && (posFirst && A[i] > 0 || !posFirst && A[i] < 0)) i++;
			while (i <= j && (posFirst && A[j] < 0 || !posFirst && A[j] > 0)) j--;

			if (i <= j) swap(A[i++], A[j--]);
		}

		return i;
	}
};

//class Solution {
//public:
//	void rerange(vector<int> &A) {
//		vector<int> positive;
//		vector<int> negative;
//
//		for (int i : A) {
//			if (i > 0) positive.push_back(i);
//			else negative.push_back(i);
//		}
//
//		vector<int> tmp;
//		if (positive.size() > negative.size()) {
//			tmp = interleave(positive, negative);
//		}
//		else {
//			tmp = interleave(negative, positive);
//		}
//
//		for (int i = 0; i < A.size(); i++) {
//			A[i] = tmp[i];
//		}
//	}
//
//	vector<int> interleave(vector<int> &A, vector<int> &B) {
//		vector<int> res;
//
//		int i = 0;
//		while (i < B.size()) {
//			res.push_back(A[i]);
//			res.push_back(B[i]);
//			i++;
//		}
//		while (i < A.size()) {
//			res.push_back(A[i++]);
//		}
//
//		return res;
//	}
//};