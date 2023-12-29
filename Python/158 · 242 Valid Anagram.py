class Solution:
    """
    @param s: The first string
    @param t: The second string
    @return: true or false
    """
    def anagram(self, s, t):
        # write your code here
        if len(s) != len(t):
            return False

        char = {}

        for c in s:
            if c in char:
                char[c] += 1
            else:
                char[c] = 1

        for c in t:
            if c not in char:
                return False

            char[c] -= 1

        for key in char:
            if 0 != char[key]:
                return False
        return True
