/*
Given two numbers, number a and number b. Find the greatest common divisor of the given two numbers.
Notes:
In mathematics, the greatest common divisor (gcd) of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers.

Example1
Input: a = 10, b = 15
Output: 5
Explanation:
10 % 5 == 0
15 % 5 == 0
Example2
Input: a = 15, b = 30
Output: 15
Explanation:
15 % 15 == 0
30 % 15 == 0
*/

class Solution {
public:
	int gcd(int a, int b) {
		if (b) return gcd(b, a % b);

		return a;
	}
};

//class Solution {
//public:
//	int gcd(int a, int b) {
//		while (b) {
//			int residue = a % b;
//			a = b;
//			b = residue;
//		}
//
//		return a;
//	}
//};