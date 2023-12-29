#include <string>
#include <vector>
using namespace std;

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

解题思路：
two pointer同向双指针法
*/

class Solution {
public:
	string minWindow(string s, string t) {
		int l = 0;
		int r = 0;
		vector<int> v(128, 0);
		int cnt = t.size();
		int start = 0;
		int len = INT_MAX;

		for (int i : t) v[i]++;
		while (r < s.size()) {
			if (v[s[r++]]-- > 0) cnt--;
			while (!cnt) {
				if (r - l < len) {
					len = r - l;
					start = l;
				}
				if (!v[s[l++]]++) cnt++;
			}
		}
		return INT_MAX == len ? "" : s.substr(start, len);
	}
};