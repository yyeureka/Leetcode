from typing import (
    List,
)

class Solution:
    """
    @param str: A string
    @return: all permutations
             we will sort your return value in output
    """
    def string_permutation2(self, str: str) -> List[str]:
        # write your code here
        chars = sorted(str)  # key point
        valid = [True for _ in range(len(chars))]
        res = []
        self.helper(chars, valid, '', res)

        return res

    def helper(self, chars, valid, cur, res):
        if len(cur) == len(chars):
            res.append(cur)
            return

        for i in range(len(chars)):
            if not valid[i]:
                continue
            if i > 0 and chars[i] == chars[i - 1] and valid[i - 1]:  # key point
                continue

            valid[i] = False
            self.helper(chars, valid, cur + chars[i], res)
            valid[i] = True

