/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.

解题思路：
错一位异或的结果是全1，即n^(n>>1)
*/

class Solution {
public:
	bool hasAlternatingBits(int n) {
		unsigned tmp = n ^ (n >> 1);   //这里要用unsigned，否则之后+1的时候用例会溢出
		return 0 == (tmp & (tmp + 1)); //判断全1
	}
};