from typing import (
    List,
)

# corner case 0 & 1
DICT = {'0': '', '1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs',
        '8': 'tuv', '9': 'wxyz'}


class Solution:
    """
    @param digits: A digital string
    @return: all possible letter combinations
             we will sort your return value in output
    """

    def letter_combinations(self, digits: str) -> List[str]:
        # write your code here
        if not digits:
            return []

        res = []
        cur = ''
        self.dfs(digits, 0, res, cur)

        return res

    def dfs(self, digits, index, res, cur):
        if index >= len(digits):
            res.append(cur)
            return

        digit = digits[index]

        for char in DICT[digit]:
            self.dfs(digits, index + 1, res, cur + char)  # key point, no need to append or pop
