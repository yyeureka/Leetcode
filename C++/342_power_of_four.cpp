/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Follow up: Could you solve it without loops/recursion?

Example 1:
Input: 16
Output: true
Example 2:
Input: 5
Output: false

解题思路：
1、首先是power of 2
2、&0x55555555 != 0
*/

class Solution {
public:
	bool isPowerOfFour(int num) {
		return (num > 0) && !(num & (num - 1)) && (num & 0x55555555);
	}
};