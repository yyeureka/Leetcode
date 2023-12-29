#include <unordered_map>
#include <string>
using namespace std;

/*
Given two strings s and t , write a function to determine if t is an anagram of s.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false

解题思路：类似#76
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		int cnt = s.size();
		if (cnt != t.size()) return false;

		unordered_map<char, int> m;
		for (char i : s) m[i]++;
		for (char i : t) {
			if (--m[i] < 0) return false;
		}
		return true;
	}
};