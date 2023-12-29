from typing import (
    List,
)


class Solution:
    """
    @param num: Given the candidate numbers
    @param target: Given the target number
    @return: All the combinations that sum to target
             we will sort your return value in output
    """

    def combination_sum2(self, num: List[int], target: int) -> List[List[int]]:
        # write your code here
        if not num:
            return []

        num.sort()  # deduplicate
        res = []
        cur = []
        self.dfs(num, 0, target, res, cur)

        return res

    def dfs(self, num, index, target, res, cur):
        if 0 == target:
            res.append(cur[:])
            return

        for i in range(index, len(num)):
            if num[i] > target:
                break
            if i > index and num[i] == num[i - 1]:  # deduplicate
                continue

            cur.append(num[i])
            self.dfs(num, i + 1, target - num[i], res, cur)
            cur.pop()

