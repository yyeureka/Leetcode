#include <string>
using namespace std;

/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
*/

class Trie {
private:
	class treeNode {
	public:
		bool end = false; //search和startwith用这个值区分
		treeNode *nodes[26];
	};

public:
	/** Initialize your data structure here. */
	treeNode *root;

	Trie() {
		root = new treeNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		treeNode *start = root;

		int i = 0;
		while (i < word.size()) {
			int idx = word[i] - 'a';
			if (NULL == start->nodes[idx]) {
				start->nodes[idx] = new treeNode();
			}
			start = start->nodes[idx];
			i++;
		}
		start->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		treeNode *start = root;
		int i = 0;
		while (i < word.size()) {
			int idx = word[i] - 'a';
			if (NULL == start->nodes[idx]) return false;
			start = start->nodes[idx];
			i++;
		}
		return start->end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		treeNode *start = root;
		int i = 0;
		while (i < prefix.size()) {
			int idx = prefix[i] - 'a';
			if (NULL == start->nodes[idx]) return false;
			start = start->nodes[idx];
			i++;
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/