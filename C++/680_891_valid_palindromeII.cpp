#include "head.h"

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: s = "aba"
Output: true
Explanation: Originally a palindrome.
Example 2:
Input: s = "abca"
Output: true
Explanation: Delete 'b' or 'c'.
Example 3:
Input: s = "abc"
Output: false
Explanation: Deleting any letter can not make it a palindrome.

Notice
The string will only contain lowercase characters.
The maximum length of the string is 50000.
*/

class Solution {
public:
	bool validPalindrome(string &s) {
		if (s.empty()) return true;

		int start = 0;
		int end = s.size() - 1;

		while (start < end) {
			if (s[start] != s[end]) {
				if (!isPalindrome(s, start, end - 1) && !isPalindrome(s, start + 1, end)) {
					return false;
				}
				break; //рв╢М
			}

			start++; //рв╢М
			end--;
		}
		return true;
	}

	bool isPalindrome(string &s, int start, int end) {
		if (start >= end) return true;

		while (start < end) {
			if (s[start++] != s[end--]) return false;
		}

		return true;
	}
};