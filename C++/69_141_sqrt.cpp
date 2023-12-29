/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2
Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
the decimal part is truncated, 2 is returned.

解题思路：
1、binary search
2、从2~x/2依次计算平方值并判断，O(n)
注意int溢出，中间值用long long
*/

class Solution {
public:
	int sqrt(int x) {
		if (x <= 0) return 0;

		long long start = 1; //中间值会溢出！！
		long long end = x;

		while (start + 1 < end) {
			long long mid = start + (end - start) / 2;

			if (mid * mid == x) return mid;
			else if (mid * mid < x) start = mid;
			else end = mid;
		}

		if (end * end <= x) return end;
		if (start * start <= x) return start;
		return 0;
	}
};

//class Solution {
//public:
//	int sqrt(int x) {
//		if (x <= 0) return 0;
//
//		int res = 0;
//		int start = 1;
//		int end = x;
//
//		while (start <= end) {
//			long long mid = start + (end - start) / 2;
//
//			if (mid * mid == x) return mid;
//			else if (mid * mid < x) {
//				res = mid; //易错
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
//	int mySqrt(int x) {
//		int l = 1;
//		int r = x;
//		while (l <= r) {
//			long long mid = l + (r - l) / 2; //易错 中间值溢出
//			if (mid * mid > x) r = mid - 1;
//			else {
//				if ((mid + 1) * (mid + 1) > x) return mid; //易错
//				l = mid + 1;
//			}
//		}
//		return 0;
//	}
//};