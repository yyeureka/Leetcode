class TrieNode:
    def __init__(self):
        self.child = {}
        self.end = False  # 区分 search 和 startwith


class Trie:

    def __init__(self):
        self.root = TrieNode()

    """
    @param: word: a word
    @return: nothing
    """

    def insert(self, word):
        if not word:
            return

        p = self.root
        for c in word:
            if c not in p.child:
                p.child[c] = TrieNode()
            p = p.child[c]
        p.end = True

    """
    @param: word: A string
    @return: if the word is in the trie.
    """

    def search(self, word):
        p = self.root
        for c in word:
            if c not in p.child:
                return False
            p = p.child[c]

        return p.end

    """
    @param: prefix: A string
    @return: if there is any word in the trie that starts with the given prefix.
    """

    def startsWith(self, prefix):
        p = self.root
        for c in prefix:
            if c not in p.child:
                return False
            p = p.child[c]

        return True