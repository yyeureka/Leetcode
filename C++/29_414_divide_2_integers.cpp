#include <iostream>
using namespace std;

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.
Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Example 2:
Input: dividend = 7, divisor = -3
Output: -2

解题思路：这道题神坑！！！！倍增法
1、被除数为0时，返回0
2、除数为1时，返回被除数
   除数为-1时，返回被除数的负，当被除数为-2^31，结果2^31溢出，返回2147483647
3、在被除数<=除数的情况下，被除数一直<<2，倍数<<2
4、除数-被除数，结果+倍数
5、重复3、4，直到除数>被除数时结束

注意事项：
是有符号的除！先去符号得到结果后，再加上符号。
中间变量做<<1的时候是可能溢出的，用long long类型定义
*/

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (0 == dividend) return 0;
		if (1 == divisor) return dividend;
		if (-1 == divisor) {
			if (INT_MIN == dividend) return INT_MAX; //只有这种情况结果会溢出
			else return -1 * dividend;
		}

		int res = 0;
		int sign = dividend > 0 == divisor > 0 ? 1 : -1;
		long long numer = fabs(dividend); //中间变量可能溢出,long long不能用abs
		long long denom = fabs(divisor);
		while (numer >= denom) { //易错，不能写成>
			for (long long i = denom, time = 1; i <= numer; i <<= 1, time <<= 1) {
				numer -= i;
				res += time;
			}
		}
		return sign * res;
	}
};