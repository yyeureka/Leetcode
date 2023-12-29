class Solution:
    """
    @param s: A string
    @return: A string
    """
    def reverse_words(self, s: str) -> str:
        # write your code here
        words = s.split()
        return ' '.join(reversed(words))