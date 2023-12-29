#include <string>
#include <algorithm>
using namespace std;

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:
Input: "race a car"
Output: false

解题思路：two pointer
将大写变成小写以后，再a==b判断是否相等
*/

class Solution {
public:
	bool isValid(char c) {
		return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	}

	bool isEqual(char a, char b) {
		if (a >= 'A' && a <= 'Z') a += ('a' - 'A');
		if (b >= 'A' && b <= 'Z') b += ('a' - 'A');

		return a == b;
	}

	bool isPalindrome(string s) {
		if (s.empty()) return true;

		int i = 0;
		int j = s.size() - 1;
		while (i < j) { //不用<=，如果是奇数，i==j就可以结束，如果是偶数，肯定是i>j
			while (i < j && !isValid(s[i])) i++;
			while (i < j && !isValid(s[j])) j--;

			if (!isEqual(s[i++], s[j--])) return false; //易错 忘记++ --会TLE
		}

		return true;
	}
};