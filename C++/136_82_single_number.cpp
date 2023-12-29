#include <vector>
using namespace std;

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1
Example 2:
Input: [4,1,2,1,2]
Output: 4

解题思路：
a^a为0，0^a为a
把所有字符依次全部^，最后的结果为少的那个数字
*/

class Solution {
public:
	int singleNumber(vector<int> &A) {
		int target = 0;

		for (int num : A) {
			target ^= num;
		}

		return target;
	}
};