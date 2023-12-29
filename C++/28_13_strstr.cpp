#include <string>
using namespace std;

/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
public:
	int strStr(string haystack, string needle) {
		int s_len = haystack.size();
		int t_len = needle.size();

		for (int i = 0; i <= s_len - t_len; i++) {
			int j;
			for (j = 0; j < t_len; j++) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (t_len == j) return i;
		}
		return -1;
	}
};

//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (needle.empty()) return 0;
//		if (haystack.empty()) return -1;
//
//		auto iter = haystack.find(needle);
//		if (iter == haystack.npos)
//		{
//			return -1;
//		}
//		return iter;
//	}
//};