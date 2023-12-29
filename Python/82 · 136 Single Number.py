from typing import (
    List,
)

class Solution:
    """
    @param a: An integer array
    @return: An integer
    """
    def single_number(self, a: List[int]) -> int:
        # write your code here
        res = 0

        for i in a:
            res ^= i

        return res


class Solution:
    """
    @param a: An integer array
    @return: An integer
    """
    def single_number(self, a: List[int]) -> int:
        # write your code here
        hash = set()

        for i in a:
            if i not in hash:
                hash.add(i)
            else:
                hash.remove(i)

        for i in hash:
            return i
