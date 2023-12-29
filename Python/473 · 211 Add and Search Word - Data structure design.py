class TrieNode:
    def __init__(self):
        self.child = {}
        self.end = False

class WordDictionary:
    """
    @param: word: Adds a word into the data structure.
    @return: nothing
    """
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word):
        p = self.root

        for c in word:
            if c not in p.child:
                p.child[c] = TrieNode()
            p = p.child[c]

        p.end = True

    """
    @param: word: A word could contain the dot character '.' to represent any one letter.
    @return: if the word is in the data structure.
    """
    def search(self, word):
        return self.helper(word, 0, self.root)

    def helper(self, word, idx, p):
        if idx >= len(word):
            return p.end

        if '.' != word[idx]:
            if word[idx] not in p.child:
                return False
            return self.helper(word, idx + 1, p.child[word[idx]])

        for c in p.child:
            if self.helper(word, idx + 1, p.child[c]):
                return True
        return False


