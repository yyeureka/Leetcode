from typing import (
    List,
)


class Solution:
    """
    @param s: An array of char
    @param offset: An integer
    @return: nothing
    """

    def rotate_string(self, s: List[str], offset: int):
        # write your code here
        if not s or 0 == offset:
            return

        offset %= len(s)  # tricky
        s[:] = s[len(s) - offset:] + s[:len(s) - offset]

        # def reverse(s, i, j):
        #     while i < j:
        #         s[i], s[j] = s[j], s[i]
        #         i += 1
        #         j -= 1

        # reverse(s, len(s) - offset, len(s) - 1)
        # reverse(s, 0, len(s) - offset - 1)
        # reverse(s, 0, len(s) - 1)
