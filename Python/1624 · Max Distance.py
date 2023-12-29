from typing import (
    List,
)

class TrieNode:
    def __init__(self):
        self.child = {}
        self.height = 0
        self.end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        p = self.root
        for i, c in enumerate(word):
            if c not in p.child:
                p.child[c] = TrieNode()
            p = p.child[c]
            p.height = max(p.height, len(word) - i)  # key point
        p.end = True


class Solution:
    """
    @param s: the list of binary string
    @return: the max distance
    """
    def get_ans(self, s: List[str]) -> int:
        # Write your code here
        trie = Trie()
        for i in s:
            trie.insert(i)

        return self.helper(trie.root)

    def helper(self, node):
        height = 0

        for c in node.child:
            height = max(height, self.helper(node.child[c]))

        if 2 == len(node.child):
            height = max(height, node.child['0'].height + node.child['1'].height)
        elif 1 == len(node.child) and node.end:
            height = max(height, node.height - 1)  # key point

        return height
