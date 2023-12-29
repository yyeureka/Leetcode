class TrieNode:
    def __init__(self):
        self.child = {}
        self.val = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word, val):
        p = self.root
        for c in word:
            if c not in p.child:
                p.child[c] = TrieNode()
            p = p.child[c]
            p.val += val  # key point

    def search(self, word):
        p = self.root
        for c in word:
            if c not in p.child:
                return 0
            p = p.child[c]

        return p.val


class MapSum:
    def __init__(self):
        # write your code here
        self.dict = {}
        self.trie = Trie()

    """
    @param key: 
    @param val: 
    @return: nothing
    """

    def insert(self, key, val):
        # write your code here
        if key in self.dict:
            self.trie.insert(key, val - self.dict[key])  # key point
        else:
            self.trie.insert(key, val)

        self.dict[key] = val

    """
    @param prefix: 
    @return: nothing
    """

    def sum(self, prefix):
        # write your code here
        return self.trie.search(prefix)