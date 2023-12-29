class Solution:
    """
    @param str: A string
    @return: a boolean
    """

    def is_unique(self, str: str) -> bool:
        # write your code here
        chars = set()

        for i in str:
            if i in chars:
                return False

            chars.add(i)

        return True
