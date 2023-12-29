from typing import (
    List,
)

class Solution:
    """
    @param nums: a mountain sequence which increase firstly and then decrease
    @return: then mountain top
    """
    def split_string(self, s: str) -> List:
        # write your code here
        if not s:
            return []

        res = []
        cur = []

        self.dfs(s, res, cur)

        return res

    def dfs(self, s, res, cur):
        if not s:
            res.append(cur[:])  # key point, append a clone of cur
            return

        for i in range(2):
            if i >= len(s):
                break

            cur.append(s[: i + 1])
            self.dfs(s[i + 1:], res, cur)
            cur.pop()  # key point

