#include "head.h"

/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output:
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

解题思路：
直接从startDFS到end会TLE！！
bfs start->end：记录沿途单词的距离、单词路径表
dfs start->end：沿途的单词根据距离剪枝，走距离变小的那条分支，记录path
*/

class Solution {
public:
	vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
		unordered_map<string, int> distance;
		unordered_map<string, vector<string>> neighbors;

		bfs(start, end, dict, distance, neighbors);

		vector<vector<string>> paths;
		vector<string> path(1, start);

		dfs(start, end, distance, neighbors, path, paths);

		return paths;
	}

	void bfs(string &start, string &end, unordered_set<string> &dict, unordered_map<string, int> &distance, unordered_map<string, vector<string>> &neighbors) {
		queue<string> q;
		q.push(start);
		int ladder = 1;

		dict.insert(end);
		if (dict.find(start) != dict.end()) {
			dict.erase(start);
		}

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				string cur = q.front();
				q.pop();

				if (cur == end) {
					return;
				}

				string next = cur;
				for (int j = 0; j < next.size(); j++) {
					char c = next[j];

					for (char k = 'a'; k <= 'z'; k++) {
						if (k == c) {
							continue;
						}

						next[j] = k;
						if (dict.find(next) != dict.end()) {
							neighbors[cur].push_back(next); //易错：1、要建立完成的表，找到的次不能删 2、没碰过的新词才要计算distance、加进q

							if (distance.find(next) == distance.end()) {
								distance[next] = ladder + 1;
								q.push(next);
							}
						}
					}

					next[j] = c;
				}
			}

			ladder++;
		}
	}

	void dfs(string &start, string &end, unordered_map<string, int> &distance, unordered_map<string, vector<string>> &neighbors, vector<string> &path, vector<vector<string>> &paths) {
		if (start == end) {
			paths.push_back(path);
			return;
		}

		for (string next : neighbors[start]) {
			if (distance[next] <= distance[start]) { //根据距离剪枝
				continue;
			}

			path.push_back(next);
			dfs(next, end, distance, neighbors, path, paths);
			path.pop_back();
		}

	}
};