/*
Implement pow(x, n), which calculates x raised to the power n (xn).
Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

Example 1:
Input: 2.00000, 10
Output: 1024.00000
Example 2:
Input: 2.10000, 3
Output: 9.26100
Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

解题思路：
recursive/iterative快速幂算法

易错点:n可能为负，但不能直接-1*n，可能为INT_MIN

教科书一般的recursion使用场景
为了缩短时间，如果n为偶数时，res=pow(x*x, n/2)，当n为奇数时，res=x*pow(x*x, n/2)
n可能取到INT_MIN，因此本地用long long保存并使用
特殊值：x = 0.0或1.0，n = 0
*/

class Solution {
public:
	double myPow(double x, int n) {
		if (!n) return 1.0;
		if (1 == n) return x;
		if (-1 == n) return 1 / x;

		double tmp = myPow(x, n / 2);
		tmp *= tmp;

		if (n & 1) {
			if (n < 0) return tmp / x; //坑
			return tmp * x;
		}
		else return tmp;
	}
};

//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (!n) return 1.0;
//
//		int sign = n > 0 ? 1 : -1;
//		double res = 1.0;
//
//		while (n) {
//			if (n & 1) res *= x;
//
//			x *= x;
//			n /= 2; //易错，负数不能>>
//		}
//
//		if (sign > 0) return res;
//		return 1.0 / res;
//	}
//};