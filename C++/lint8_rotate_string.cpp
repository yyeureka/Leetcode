#include "head.h"
/*
Given a string(Given in the way of char array) and an offset, rotate the string by offset in place. (rotate from left to right).

Example 1:
Input: str="abcdefg", offset = 3
Output: str = "efgabcd"
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".
Example 2:
Input: str="abcdefg", offset = 0
Output: str = "abcdefg"
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "abcdefg".
Example 3:
Input: str="abcdefg", offset = 1
Output: str = "gabcdef"
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "gabcdef".
Example 4:
Input: str="abcdefg", offset =2
Output: str = "fgabcde"
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "fgabcde".
Example 5:
Input: str="abcdefg", offset = 10
Output: str = "efgabcd"
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".

Challenge
Rotate in-place with O(1) extra memory.

Clarification
in place means you should change string s in the function. You don't return anything.

Notice
offset >= 0
the length of str >= 0
Make changes on the original input data
*/

class Solution {
public:
	void rotateString(string &str, int offset) {
		if (str.empty()) return; //易错

		int size = str.size();
		offset = size - offset % size; //易错
		if (!offset) return; //优化

		reverse(str.begin(), str.begin() + offset);
		reverse(str.begin() + offset, str.end());
		reverse(str.begin(), str.end());

		return;
	}
};