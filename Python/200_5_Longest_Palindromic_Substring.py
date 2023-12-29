class Solution:
    """
    @param s: input string
    @return: a string as the longest palindromic substring
    """

    def longest_palindrome(self, s: str) -> str:
        # write your code here
        start = 0
        size = 0

        for i in range(len(s)):
            l = i - 1
            r = i + 1
            while (l >= 0) and (r < len(s)) and (s[l] == s[r]):
                l -= 1
                r += 1
            if (r - l - 1) > size:
                start = l + 1
                size = r - l - 1

            l = i - 1  # tricky
            r = i
            while (l >= 0) and (r < len(s)) and (s[l] == s[r]):
                l -= 1
                r += 1
            if (r - l - 1) > size:
                start = l + 1
                size = r - l - 1

        return s[start: start + size]