#include <string>
using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

解题思路：#5的follow up类型，每扩出一个palindrome，cnt++
*/

class Solution {
public:
	int palindrome(string s, int i, int j) {
		int cnt = 0;
		while (i >= 0 && j < s.size()) {
			if (s[i--] != s[j++]) break;
			cnt++;
		}
		return cnt;
	}

	int countSubstrings(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			res += palindrome(s, i, i);
			res += palindrome(s, i, i + 1);
		}
		return res;
	}
};