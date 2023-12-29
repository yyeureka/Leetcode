#include <string>
#include <unordered_map>
using namespace std;

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Note: You may assume the string contain only lowercase letters.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.

解题思路：类似lint 685
1、hash，遍历两遍，找到第一个frequent为1的数
2、hash+queue
3、hash+linked list
*/

class Solution {
public:
	char firstUniqChar(string &str) {
		unordered_map<char, int> frequent;

		for (char c : str) {
			frequent[c]++;
		}
		for (char c : str) {
			if (1 == frequent[c]) return c;
		}
	}
};