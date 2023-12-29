/*
Write a function that add two numbers A and B.

Example 1:
Input:  a = 1, b = 2
Output: 3
Explanation: return the result of a + b.
Example 2:
Input:  a = -1, b = 1
Output: 0
Explanation: return the result of a + b.

Challenge
Of course you can just return a + b to get accepted. But Can you challenge not do it like that?(You should not use + or any arithmetic operators.)

Clarification
Are a and b both 32-bit integers?

Yes.
Can I use bit operation?

Sure you can.
Notice
There is no need to read data from standard input stream. Both parameters are given in function aplusb, your job is to calculate the sum and return it.
Students in the basic class of the algorithm only need to use the arithmetic operator ¡®+¡¯ to complete the problem, without considering the requirements of the bit operation.
*/

class Solution {
public:
	int aplusb(int a, int b) {
		if (0 == a) {
			return b;
		}
		if (0 == b) {
			return a;
		}

		return aplusb(a ^ b, (a & b) << 1); //a&bµÃµ½carry
	}
};