/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3
Example 2:
Input: a = -2, b = 3
Output: 1

解题思路：
1、a^b得到没有carry的sum
2、a&b得到carry
3、a为sum，b为carry<<1重复步骤1，直到carry为0为止
*/

class Solution {
public:
	int getSum(int a, int b) {
		while (0 != b) {
			unsigned carry = a & b;
			a = a ^ b;
			b = carry << 1;
		}
		return a;
	}
};

//class Solution {
//public:
//	int getSum(int a, int b) {
//		if (0 == b) return a;
//		return getSum(a ^ b, (unsigned)(a & b) << 1);
//	}
//};