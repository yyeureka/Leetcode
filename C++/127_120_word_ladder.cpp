#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

解题思路：
1、BFS，从beginWord开始，将差一个字母的neighbour加进queue，并依次将neighbour的neighbour加进queue
   直到与endWord相等。不将输入的vector变为unordered_set进行后续处理会TLE
2、bidirectional BFS，从前、后分别找neighbour，出现相同元素时即为成功，比直接BFS时间效率高
3、DFS直接TLE
*/

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord.size() != endWord.size()) return 0;

		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.find(endWord) == dict.end()) {
			return 0;
		}
		if (dict.find(beginWord) != dict.end()) {
			dict.erase(beginWord);
		}

		queue<string> q;
		q.push(beginWord);
		int ladder = 1;

		while (!q.empty()) {
			int size = q.size();

			for (int i = 0; i < size; i++) {
				string cur = q.front();
				q.pop();

				if (cur == endWord) {
					return ladder;
				}

				for (int j = 0; j < cur.size(); j++) {
					char c = cur[j];

					for (char k = 'a'; k <= 'z'; k++) {
						if (k == c) continue;

						cur[j] = k;
						if (dict.find(cur) != dict.end()) {
							dict.erase(cur); //先走到的单词len肯定比后走到的小，之后再走到没有意义
							q.push(cur);
						}
					}

					cur[j] = c;
				}
			}

			ladder++;
		}
		return 0;
	}
};

////bidirectional BFS
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		if (beginWord == endWord) return 1;
//
//		unordered_set<string> dict(wordList.begin(), wordList.end()); //比set时间效率高
//		auto iter = dict.find(endWord);
//		if (iter == dict.end()) return 0; //dict中endWord肯定失败
//		dict.erase(iter);				  //从dict删除endWord
//
//		unordered_set<string> begin;  //从beginWord开始的neighbour
//		unordered_set<string> end;    //从endWord开始的neighbour
//		begin.insert(beginWord);
//		end.insert(endWord);
//		unordered_set<string> *head = &begin;
//		unordered_set<string> *tail = &end;
//
//		int ladder = 2;
//		while (!begin.empty() && !end.empty()) {
//			if (begin.size() > end.size()) swap(head, tail); //时间效率 从小的那组生成新的neighbour
//
//			unordered_set<string> tmp; //保存新的neighbour
//			for (auto it = head->begin(); it != head->end(); it++) {
//				string cur = *it;
//				for (int i = 0; i < cur.size(); i++) {
//					char c = cur[i];
//					for (char j = 'a'; j <= 'z'; j++) {
//						if (j == c) continue;
//						cur[i] = j;
//						if (tail->count(cur)) return ladder;
//
//						iter = dict.find(cur);
//						if (iter != dict.end()) {
//							tmp.insert(cur);
//							dict.erase(iter);
//						}
//					}
//					cur[i] = c;
//				}
//			}
//			ladder++;
//			head->swap(tmp); //将新的一组neighbour替换
//		}
//		return 0;
//	}
//};

////DFS
//class Solution {
//public:
//	void dfs(string &start, string &end, unordered_map<string, int> &m, unordered_set<string> &dict) {
//		string tmp = start;
//		for (int i = 0; i < start.size(); i++) {
//			char c = tmp[i];
//			for (char j = 'a'; j <= 'z'; j++) {
//				if (c == j) continue;
//
//				tmp[i] = j;
//				if (tmp == end) {
//					if (!m[tmp] || m[tmp] > m[start] + 1) m[tmp] = m[start] + 1;
//					return;
//				}
//				if (dict.find(tmp) != dict.end() && (!m[tmp] || m[tmp] > m[start] + 1)) {
//					m[tmp] = m[start] + 1;
//					dfs(tmp, end, m, dict);
//				}
//				tmp[i] = c;
//			}
//		}
//	}
//
//	int ladderLength(string &start, string &end, unordered_set<string> &dict) {
//		if (start.size() != end.size()) return 0;
//
//		unordered_map<string, int> m;
//		m[start] = 1;
//		dfs(start, end, m, dict);
//		return m[end];
//	}
//};