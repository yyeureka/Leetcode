from typing import (
    List,
)

# DFS
# BFS

class Solution:
    """
    @param nums: A set of numbers.
    @return: A list of lists. All valid subsets.
             we will sort your return value in output
    """

    def subsets_with_dup(self, nums: List[int]) -> List[List[int]]:
        # write your code here
        if not nums:
            return [[]]

        nums.sort()
        res = []
        cur = []
        self.dfs(nums, 0, res, cur)

        return res

    def dfs(self, nums, index, res, cur):
        res.append(cur[:])

        for i in range(index, len(nums)):
            if i > index and nums[i] == nums[i - 1]:  # key point
                continue

            cur.append(nums[i])
            self.dfs(nums, i + 1, res, cur)
            cur.pop()

