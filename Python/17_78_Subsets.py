from typing import (
    List,
)

# DFS
# DFS 2: 2 choices for each number, skip or choose
# BFS
# Bit operation

# DFS
class Solution:
    """
    @param nums: A set of numbers
    @return: A list of lists
             we will sort your return value in output
    """

    def subsets(self, nums: List[int]) -> List[List[int]]:
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
            cur.append(nums[i])
            self.dfs(nums, i + 1, res, cur)
            cur.pop()


# DFS 2
class Solution:
    """
    @param nums: A set of numbers
    @return: A list of lists
             we will sort your return value in output
    """

    def subsets(self, nums: List[int]) -> List[List[int]]:
        # write your code here
        if not nums:
            return [[]]  # tricky

        nums.sort()  # tricky

        res = []
        cur = []
        self.dfs(nums, 0, res, cur)

        return res

    def dfs(self, nums, index, res, cur):
        if index >= len(nums):
            res.append(cur[:])
            return

        self.dfs(nums, index + 1, res, cur)  # skip current num

        cur.append(nums[index])
        self.dfs(nums, index + 1, res, cur)  # choose current num
        cur.pop()