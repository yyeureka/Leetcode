class Solution:
    """
    @param pattern: a string,denote pattern string
    @param str: a string, denote matching string
    @return: a boolean
    """

    def word_pattern_match(self, pattern: str, str: str) -> bool:
        # write your code here
        dict = {}  # letter to word
        words = set()
        return self.dfs(pattern, str, dict, words)

    def dfs(self, pattern, str, dict, words):
        if not pattern:
            return not str

        letter = pattern[0]
        if letter in dict:
            word = dict[letter]

            if word != str[:len(word)]:
                return False

            return self.dfs(pattern[1:], str[len(word):], dict, words)

        for i in range(len(str)):
            word = str[:i + 1]  # tricky

            if word in words:
                continue

            dict[letter] = word
            words.add(word)
            if self.dfs(pattern[1:], str[len(word):], dict, words):
                return True
            words.remove(word)
            dict.pop(letter)  # weird, error when put it outside the for loop

        return False
