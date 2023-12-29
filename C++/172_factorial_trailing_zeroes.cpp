/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.

解题思路：
5和5的倍数增加1个0
25和25的倍数再增加1个0
125的倍数再增加一个0
...依次类推
*/

class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		for (long long i = 5; i <= n; i *= 5) res += n / i; //用int i*5时会overflow
		return res;
	}
};