#include "head.h"

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.

Example:
Input:
board = [
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

解题思路：
1、trie，将words变为trie
2、hashmap，将所有单词的prefix加进hash
*/

class solution {
public:
	vector<string> wordsearchii(vector<vector<char>> &board, vector<string> &words) {
		if (board.empty() || words.empty()) {
			return{};
		}

		int n = board.size();
		int m = board[0].size();

		unordered_map<string, bool> prefix;
		for (string i : words) {
			for (int j = 1; j < i.size(); j++) {
				string s = i.substr(0, j);
				if (prefix.find(s) == prefix.end()) { //极易错，{b,ba}，b即为单词又为prefix
					prefix[s] = false;
				}
			}
			prefix[i] = true;
		}

		vector<string> results;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dfs(board, i, j, prefix, "", results); //入参不取址可以直接传""进去
			}
		}

		return results;
	}

	void dfs(vector<vector<char>> &board, int row, int col, unordered_map<string, bool> &prefix, string word, vector<string> &results) {
		if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || '#' == board[row][col]) {
			return;
		}

		word += board[row][col];
		if (prefix.find(word) == prefix.end()) {
			return;
		}
		if (prefix[word]) {
			results.push_back(word); //极易错，1、找到一个单词不能停，2、防止重复找到置为false
			prefix[word] = false;
		}

		char c = board[row][col];
		board[row][col] = '#';
		dfs(board, row + 1, col, prefix, word, results);
		dfs(board, row - 1, col, prefix, word, results);
		dfs(board, row, col + 1, prefix, word, results);
		dfs(board, row, col - 1, prefix, word, results);
		board[row][col] = c;
	}
};

//class Solution {
//public:
//	struct trieNode {
//		trieNode * next[26]; //不能写成vector<trieNode *> next(26)
//		string word;		 //word末尾的节点保存完整word
//	};
//
//	void insert(trieNode * root, string word) {
//		trieNode *cur = root;
//
//		for (char c : word) {
//			int index = c - 'a';
//			if (NULL == cur->next[index]) {
//				cur->next[index] = new trieNode();
//			}
//			cur = cur->next[index];
//		}
//		cur->word = word;
//	}
//
//	vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
//		if (board.empty() || words.empty()) {
//			return{};
//		}
//
//		int n = board.size();
//		int m = board[0].size();
//
//		trieNode * root = new trieNode();
//		for (string i : words) {
//			insert(root, i);
//		}
//
//		vector<string> results;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				dfs(board, i, j, root, results);
//			}
//		}
//
//		return results;
//	}
//
//	void dfs(vector<vector<char>> &board, int row, int col, trieNode * root, vector<string> &results) {
//		if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || '#' == board[row][col]) {
//			return;
//		}
//
//		char c = board[row][col];
//		root = root->next[c - 'a'];
//
//		if (NULL == root) {
//			return;
//		}
//		if (!root->word.empty()) { //极易错，1、找到一个单词不能停，2、防止重复找到置为false
//			results.push_back(root->word);
//			root->word = "";
//		}
//
//		board[row][col] = '#';
//		dfs(board, row + 1, col, root, results);
//		dfs(board, row - 1, col, root, results);
//		dfs(board, row, col + 1, root, results);
//		dfs(board, row, col - 1, root, results);
//		board[row][col] = c;
//	}
//};

