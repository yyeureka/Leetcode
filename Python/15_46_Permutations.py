from typing import (
    List,
)


class Solution:
    """
    @param nums: A list of integers.
    @return: A list of permutations.
             we will sort your return value in output
    """

    def permute(self, nums: List[int]) -> List[List[int]]:
        # write your code here
        if not nums:
            return [[]]

        res = []
        cur = []
        valid = [True for i in range(len(nums))]
        self.dfs(nums, valid, res, cur)

        return res

    def dfs(self, nums, valid, res, cur):
        if len(nums) == len(cur):
            res.append(cur[:])
            return

        for i in range(len(nums)):
            if not valid[i]:
                continue

            cur.append(nums[i])
            valid[i] = False
            self.dfs(nums, valid, res, cur)
            cur.pop()
            valid[i] = True

