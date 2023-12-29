class Solution:
    """
    @param s: A string
    @return: Whether the string is a valid palindrome
    """

    def is_palindrome(self, s: str) -> bool:
        # write your code here
        if not s:
            return True

        l = 0
        r = len(s) - 1

        while l < r:
            while (not s[l].isalnum()) & (l < r):
                l += 1
            while (not s[r].isalnum()) & (l < r):
                r -= 1

            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1

        return True


