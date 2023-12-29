from typing import (
    List,
)


class Solution:
    """
    @param candidates: A list of integers
    @param target: An integer
    @return: A list of lists of integers
             we will sort your return value in output
    """

    def combination_sum(self, candidates: List[int], target: int) -> List[List[int]]:
        # write your code here
        if not candidates:
            return []

        nums = sorted(list(set(candidates)))  # deduplicate

        res = []
        cur = []
        self.dfs(nums, target, res, cur, 0)

        return res

    def dfs(self, nums, target, res, cur, index):
        if 0 == target:
            res.append(cur[:])  # key point
            return

        for i in range(index, len(nums)):
            if nums[i] > target:
                break

            cur.append(nums[i])
            self.dfs(nums, target - nums[i], res, cur, i)
            cur.pop()  # key point


