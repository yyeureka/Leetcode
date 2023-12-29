#include <iostream>
using namespace std;

/*
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:
Input: 120
Output: 21
Note:
Assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		if (x < 0) {
			if (INT_MIN == x) return 0; //-2147483648��ʹreverse��Ҳ��overflow��
			sign = -1;
			x *= -1;
		}

		long long res = 0;
		while (x > 0) {
			res *= 10;
			res += x % 10;
			if (res > INT_MAX) return 0; //signΪ����resΪ2147483648������ǲ����ڵ�
			x /= 10;
		}

		return sign > 0 ? res : -1 * res;
	}
};