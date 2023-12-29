/*
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?

Example 1:
Input: 27
Output: true
Example 2:
Input: 0
Output: false
Example 3:
Input: 9
Output: true
Example 4:
Input: 45
Output: false

解题思路：
1、while n能整除3的时候n/=3，最后1==n时即为true
2、3^19为int内3的最大幂，2^19能整除的n即为3的幂
*/

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		while (0 == n % 3) n /= 3;
		return 1 == n;
	}
};

//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		if (1 == n) return true;
//		if (n <= 0 || 0 != n % 3) return false;
//		return isPowerOfThree(n / 3);
//	}
//};

//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		return (n > 0) && (0 == 1162261467 % n); //3^19为int范围内最大的3的幂
//	}
//};