#include "head.h"

/*
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Example 1:
Input: 9
Output: 10
Example 2:
Input: 1
Output: 1

Challenge
O(n log n) or O(n) time.

Notice
Note that 1 is typically treated as an ugly number.

解题思路：
1、dp，好难想出来，背诵全文吧
2、set，从1开始，每pop出堆顶，*2*3*5 push进去，因为可能重复，不能用priority_queue，O(nlogn)
*/

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> uglyNum(n, 1);

		int p2 = 0;
		int p3 = 0;
		int p5 = 0;

		for (int i = 1; i < n; i++) {
			uglyNum[i] = min(uglyNum[p2] * 2, min(uglyNum[p3] * 3, uglyNum[p5] * 5));

			if (uglyNum[i] == uglyNum[p2] * 2) {
				p2++;
			}
			if (uglyNum[i] == uglyNum[p3] * 3) {
				p3++;
			}
			if (uglyNum[i] == uglyNum[p5] * 5) {
				p5++;
			}
		}

		return uglyNum[n - 1];
	}
};

//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		set<long long, greater<long long>> uglyNum; //易错，int会溢出
//		uglyNum.insert(1);
//
//		for (int i = 0; i < n - 1; i++) {
//			long long cur = *(--uglyNum.end());
//			uglyNum.insert(cur * 2);
//			uglyNum.insert(cur * 3);
//			uglyNum.insert(cur * 5);
//			uglyNum.erase(--uglyNum.end());
//		}
//
//		return *(--uglyNum.end());
//	}
//};