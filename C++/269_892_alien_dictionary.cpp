#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <xfunctional>
using namespace std;

/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
Notes:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return the smallest in normal lexicographical order

Example 1:
Input：["wrt","wrf","er","ett","rftt"]
Output："wertf"
Explanation：
from "wrt"and"wrf" ,we can get 't'<'f'
from "wrt"and"er" ,we can get 'w'<'e'
from "er"and"ett" ,we can get 'r'<'t'
from "ett"and"rtff" ,we can get 'e'<'r'
So return "wertf"
Example 2:
Input：["z","x"]
Output："zx"
Explanation：
from "z" and "x"，we can get 'z' < 'x'
So return "zx"

解题思路：topological sort
依次检查每个word，梳理字符顺序
每个字符加进indegree
如果存在cycle，最终结果res的长度将小于indegree的长度即总字符数
*/

class Solution {
public:
	/**
	* @param words: a list of words
	* @return: a string which is correct order
	*/
	string alienOrder(vector<string> &words) {
		if (words.empty()) return "";

		unordered_map<char, vector<char>> connection;
		unordered_map<char, int> indegree;
		string pre = "";
		for (string s : words) {
			int i = 0;
			for (; i < pre.size() && i < s.size(); i++) {
				if (pre[i] == s[i]) continue;

				connection[pre[i]].push_back(s[i]);
				indegree[s[i]]++;
				break; //易错
			}

			for (; i < s.size(); i++) {
				if (indegree.find(s[i]) == indegree.end()) indegree.insert({ s[i], 0 });
			}

			pre = s; //易错
		}

		priority_queue<char, vector<char>, greater<char>> pq; //保证lexicographical
		for (auto i : indegree) {
			if (!i.second) pq.push(i.first);
		}

		string res = "";
		while (!pq.empty()) {
			char cur = pq.top();
			pq.pop();
			res += cur;

			for (char i : connection[cur]) {
				if (0 == --indegree[i]) pq.push(i);
			}
		}

		return res.size() == indegree.size() ? res : ""; //易错，判断是否有cycle
	}
};