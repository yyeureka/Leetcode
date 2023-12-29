#include <unordered_map>
#include <string>
using namespace std;

/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

解题思路：类似题#76、#438
*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) return false;

		int char_cnt = s1.size();
		unordered_map<char, int> m;
		for (char i : s1) m[i]++;
		for (int i = 0; i < s2.size(); i++) {
			if (--m[s2[i]] >= 0) char_cnt--;
			if (i >= s1.size()) {
				if (++m[s2[i - s1.size()]] > 0) char_cnt++;
			}
			if (0 == char_cnt) return true;
		}
		return false;
	}
};