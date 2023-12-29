class TrieNode:
    def __init__(self):
        self.child = {}
        self.end = False  # 区分 search 和 startwith


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        if not word:
            return

        p = self.root
        for c in word:
            if c not in p.child:
                p.child[c] = TrieNode()
            p = p.child[c]
        p.end = True

    def search(self, word):
        p = self.root
        for c in word:
            if c not in p.child:
                return False
            p = p.child[c]

        return p.end

    def startsWith(self, prefix):
        p = self.root
        for c in prefix:
            if c not in p.child:
                return False
            p = p.child[c]

        return True