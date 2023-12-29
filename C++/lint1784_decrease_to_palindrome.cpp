#include <string>
using namespace std;

/*
Given a string s with a-z. We want to change s into a palindrome with following operations:
1. change 'z' to 'y';
2. change 'y' to 'x';
3. change 'x' to 'w';
................
24. change 'c' to 'b';
25. change 'b' to 'a';
Returns the number of operations needed to change s to a palindrome at least.

Example 1:
Input: "abc"
Output: 2
Explanation:
1. Change 'c' to 'b': "abb"
2. Change the last 'b' to 'a': "aba"
Example 2:
Input: "abcd"
Output: 4
*/

class Solution {
public:
	/**
	* @param s: the string s
	* @return: the number of operations at least
	*/
	int numberOfOperations(string &s) {
		int i = 0;
		int j = s.size() - 1;
		int res = 0;
		while (i < j) {
			res += abs(s[i++] - s[j--]);
		}
		return res;
	}
};