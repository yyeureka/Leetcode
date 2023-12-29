#include "head.h"

/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8
Example 2:
Input: a = 2, b = [1,0]
Output: 1024

解题思路：#50、lint140进阶版
以a^123为例
a^123 = a^120 * a^3 = (a^12)^10 * a^3 = (a^1)^100 * (a^2)^10 * a^3
*/

class Solution {
public:
	int base = 1337;

	int pow(int a, int b) {
		if (1 == a || !b) return 1;
		if (1 == b) return a % base;

		long long tmp = pow(a, b / 2);
		tmp = (tmp * tmp) % base;

		if (b & 1) return (tmp * a) % base;
		else return tmp;
	}

	int superPow(int a, vector<int>& b) {
		long long res = 1;

		for (int j = 0; j < b.size(); j++) {
			res = pow(res, 10);
			res = (res * pow(a, b[j])) % base;
		}

		return res;
	}
};