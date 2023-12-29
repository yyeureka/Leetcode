class Solution:
    """
    @param pattern: a string, denote pattern string
    @param teststr: a string, denote matching string
    @return: an boolean, denote whether the pattern string and the matching string match or not
    """

    def word_pattern(self, pattern: str, teststr: str) -> bool:
        # write your code here
        if not pattern:
            return not teststr
        if not teststr:
            return not pattern

        s = teststr.split(' ')
        if len(pattern) != len(s):
            return False

        dict = {}
        words = set()
        for i in range(len(pattern)):
            if pattern[i] in dict:
                if s[i] != dict[pattern[i]]:
                    return False
            else:
                if s[i] in words:  # tricky
                    return False

                dict[pattern[i]] = s[i]
                words.add(s[i])

        return True






