#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

解题思路：相似题#76、#567
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (p.size() > s.size()) return{};
		vector<int> res;

		unordered_map<char, int> m;
		int char_cnt = p.size();
		for (char i : p) m[i]++;

		for (int i = 0; i < s.size(); i++) {
			if (--m[s[i]] >= 0) char_cnt--;
			if (i >= p.size()) {
				if (++m[s[i - p.size()]] > 0) char_cnt++;
			}
			if (0 == char_cnt) res.push_back(i - p.size() + 1);
		}
		return res;
	}
};