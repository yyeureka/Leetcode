#include <string>
#include <unordered_map>
using namespace std;

/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

hash map或hash set或vector都能解决，但map效率最高
*/

class Solution {
public:
	int longestPalindrome(string s) {
		int res = 0;
		unordered_map<char, int> m;
		for (char c : s) {
			m[c]++;
			if (!(m[c] & 1)) res += 2;
		}

		if (s.size() > res) res++; //这里容易忘
		return res;
	}
};

//class Solution {
//public:
//	int longestPalindrome(string s) {
//		int res = 0;
//		unordered_map<char, int> m;
//		for (char c : s) m[c]++;
//		for (auto i = m.begin(); i != m.end(); i++) {
//			if (i->second & 1) {
//				res += i->second - 1;
//			}
//			else res += i->second;
//		}
//		if (s.size() > res) res++;
//		return res;
//	}
//};

//class Solution {
//public:
//	int longestPalindrome(string &s) {
//		int res = 0;
//		vector<int> upper(26, 0);
//		vector<int> lower(26, 0);
//
//		for (char c : s) {
//			if (c >= 'a') lower[c - 'a']++;
//			else upper[c - 'A']++;
//		}
//		for (int i = 0; i < 26; i++) {
//			res += lower[i] / 2 * 2;
//			res += upper[i] / 2 * 2;
//		}
//
//		return res == s.length() ? res : res + 1;
//	}
//};