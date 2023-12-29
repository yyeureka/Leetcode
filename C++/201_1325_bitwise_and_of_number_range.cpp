/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: [5,7]
Output: 4
Example 2:
Input: [0,1]
Output: 0

解题思路：
结果为m和n对应相等的高位bits
*/

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int shift = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			shift++;
		}
		return m << shift;
	}
};

//class Solution {
//public:
//	int rangeBitwiseAnd(int m, int n) {
//		if (m == n) return m;
//		return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
//	}
//};