/*
Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

Example 1:
Input: 0
Output: 0
Explanation:
0 = 0(2) -> 0(2) = 0
Example 2:
Input: 5
Output: 10
Explanation:
5 = 101(2) -> 1010(2) = 10

解题思路：
straightforward，取出所有奇数位左移，取出所有偶数位右移，结果相与
*/

class Solution {
public:
	int swapOddEvenBits(int x) {
		return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
	}
};