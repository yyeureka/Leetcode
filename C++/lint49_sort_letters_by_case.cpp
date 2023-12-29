#include "head.h"

/*
Given a string which contains only letters. Sort it by lower case first and upper case second.

Example 1:
Input:  "abAcD"
Output:  "acbAD"

Example 2:
Input: "ABC"
Output:  "ABC"

Challenge
Do it in one-pass and in-place.

Notice
It's NOT necessary to keep the original order of lower-case letters and upper case letters.

解题思路：partition
*/

class Solution {
public:
	void sortLetters(string &chars) {
		if (chars.empty()) return;

		int i = 0;
		int j = chars.size() - 1;

		while (i <= j) {
			while (i <= j && isLower(chars[i])) i++;
			while (i <= j && !isLower(chars[j])) j--;

			if (i <= j) swap(chars[i++], chars[j--]);
		}
	}

	bool isLower(char c) {
		return c >= 'a' && c <= 'z';
	}
};