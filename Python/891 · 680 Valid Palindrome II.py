class Solution:
    """
    @param s: a string
    @return: whether you can make s a palindrome by deleting at most one character
    """

    def valid_palindrome(self, s: str) -> bool:
        # Write your code here
        i = 0
        j = len(s) - 1

        while i < j:
            if s[i] != s[j]:
                if not self.is_palindrome(s, i + 1, j) and not self.is_palindrome(s, i, j - 1):
                    return False
                return True

            i += 1
            j -= 1

        return True

    def is_palindrome(self, s, i, j):
        while i < j:
            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True
