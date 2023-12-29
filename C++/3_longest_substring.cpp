#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

解题思路：同向双指针法，建立128维的一维数组计数，控制字符不重复
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int l = 0;
		vector<int> v(128, 0);
		for (int i = 0; i < s.size(); i++) {
			v[s[i]]++;
			while (v[s[i]] > 1) v[s[l++]]--;
			res = max(res, i - l + 1);
		}
		return res;
	}
};

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int res = 0;
//		int l = 0;
//		unordered_set<char> u;
//		for (int i = 0; i < s.size(); i++) {
//			if (u.find(s[i]) != u.end()) {
//				while (s[l] != s[i]) {
//					u.erase(s[l]);
//					l++;
//				}
//				l++;
//			}
//			else u.insert(s[i]);
//
//			res = max(res, i - l + 1);
//		}
//		return res;
//	}
//};

//void main()
//{
//	//string a = " ";  // 1
//	string a = "dvdf";
//	Solution s;
//	cout << s.lengthOfLongestSubstring(a) << endl;
//}