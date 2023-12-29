#include <string>
using namespace std;

/*
We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
Note:
A and B will have length at most 100.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true
Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

解题思路：
B为A的rotate的条件是：1.A和B的size相等 2.B是A+A的substring
*/

class Solution {
public:
	bool rotateString(string A, string B) {
		if (B.size() != A.size()) return false;  //这个条件不能忘
		A += A;
		return A.find(B) != A.npos;
	}
};