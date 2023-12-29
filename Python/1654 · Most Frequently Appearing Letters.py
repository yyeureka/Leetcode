class Solution:
    """
    @param str: the str
    @return: the sum that the letter appears the most
    """
    def most_frequently_appearing_letters(self, str: str) -> int:
        # Write your code here.
        res = 0
        hash = {}

        for i in str:
            hash[i] = hash.get(i, 0) + 1
            if hash[i] > res:
                res = hash[i]

        return res

