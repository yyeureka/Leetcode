#include "head.h"

/*
Calculate the an % b where a, b and n are all 32bit non-negative integers.

Example
For 2^31 % 3 = 2

For 100^1000 % 1000 = 0

Challenge
O(logn)

����˼·��recursive/iterative�����ݣ�����#50
*/

class Solution {
public:
	int fastPower(int a, int b, int n) {
		if (!n) return 1 % b;
		if (1 == n) return a % b;

		long long tmp = fastPower(a, b, n / 2) % b; //shit���ֻ����
		tmp = (tmp * tmp) % b;

		if (n & 1) return (tmp * a) % b;
		else return tmp;
	}
};

//class Solution {
//public:
//	int fastPower(int a, int b, int n) {
//		if (!n) return 1 % b;
//
//		long long base = a; //�״�
//		long long res = 1;
//
//		while (n) {
//			if (n & 1) res = (res * base) % b;
//
//			base = (base * base) % b;
//			n /= 2;
//		}
//
//		return res;
//	}
//};