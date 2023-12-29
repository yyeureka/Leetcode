/*
Using O(1) time to check whether an integer n is a power of 2.

Example 1:
Input: 4
Output: true

Example 2:
Input:  5
Output: false

Challenge
O(1) time

����˼·��x&(x-1)
*/

class Solution {
public:
	bool checkPowerOf2(int n) {
		return n > 0 && 0 == (n & (n - 1)); //����������˾ʹ���
	}
};

//class Solution {
//public:
//	bool checkPowerOf2(int n) {
//		int count = 0;
//
//		while (n > 0) {
//			n = n & (n - 1);
//			count++;
//		}
//
//		return 1 == count ? true : false;
//	}
//};