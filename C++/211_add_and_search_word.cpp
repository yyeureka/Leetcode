#include <string>
using namespace std;

/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
Note:
You may assume that all words are consist of lowercase letters a-z.

Example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

解题思路：backtracking+trie
*/

class WordDictionary {
private:
	struct trieNode {
		bool end = false;
		trieNode *next[26];
	};
public:
	/** Initialize your data structure here. */
	trieNode *root;
	WordDictionary() {
		root = new trieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		trieNode *t = root;
		for (auto i : word) {
			int idx = i - 'a';
			if (NULL == t->next[idx]) t->next[idx] = new trieNode();
			t = t->next[idx];
		}
		t->end = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		if (word.empty()) return false;
		return dfs(word, 0, root);
	}

	bool dfs(string word, int i, trieNode *node) {
		if (i >= word.size()) return node->end;

		char c = word[i];
		if ('.' != c) {
			if (NULL == node->next[c - 'a']) return false;
			return dfs(word, i + 1, node->next[c - 'a']);
		}
		else {
			for (int j = 0; j < 26; j++) {
				if (node->next[j] && dfs(word, i + 1, node->next[j])) return true;
			}
			return false;
		}
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/