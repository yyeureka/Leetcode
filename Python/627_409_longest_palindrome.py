class Solution:
    """
    @param s: a string which consists of lowercase or uppercase letters
    @return: the length of the longest palindromes that can be built
    """

    def longest_palindrome(self, s: str) -> int:
        # write your code here
        res = 0
        count = {}

        for c in s:
            if c in count:  # tricky
                count[c] += 1
            else:
                count[c] = 1

            if not (count[c] & 1):
                res += 2

        if len(s) > res:  # clever
            res += 1

        return res


