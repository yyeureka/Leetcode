/*
Determine the number of bits required to flip if you want to convert integer n to integer m.

Example 1:
Input: n = 31, m = 14
Output:  2
Explanation:
(11111) -> (01110) there are two different bits.
Example 2:
Input: n = 1, m = 7
Output:  2
Explanation:
(001) -> (111) will change two bits.

Notice
Both n and m are 32-bit integers.

解题思路：跟461求hamming distance一个意思
*/

class Solution {
public:
	int bitSwapRequired(int a, int b) {
		int diff = a ^ b;
		int count = 0;

		while (0 != diff) {
			diff &= diff - 1;
			count++;
		}

		return count;
	}
};