from typing import (
    List,
)

# dfs memo
# dp1 dict
# dp2 list MLE
# dfs TLE


# dfs memo
class Solution:
    """
    @param nums: the given array
    @param s: the given target
    @return: the number of ways to assign symbols to make sum of integers equal to target S
    """
    def find_target_sum_ways(self, nums: List[int], s: int) -> int:
        # Write your code here
        memo = {}
        return self.helper(nums, 0, s, memo)

    def helper(self, nums, index, target, memo):
        if index >= len(nums):
            if 0 == target:
                return 1
            return 0
        if (index, target) in memo:
            return memo[(index, target)]

        res = 0
        res += self.helper(nums, index + 1, target - nums[index], memo)
        res += self.helper(nums, index + 1, target + nums[index], memo)
        memo[(index, target)] = res

        return res


# dp1
class Solution:
    """
    @param nums: the given array
    @param s: the given target
    @return: the number of ways to assign symbols to make sum of integers equal to target S
    """

    def find_target_sum_ways(self, nums: List[int], s: int) -> int:
        # Write your code here
        dp = {0: 1}

        for i in nums:
            tmp = {}
            for j in dp:
                tmp[j + i] = tmp.get(j + i, 0) + dp[j]
                tmp[j - i] = tmp.get(j - i, 0) + dp[j]

            dict = tmp

        return dp.get(s, 0)


# dp2
class Solution:
    """
    @param nums: the given array
    @param s: the given target
    @return: the number of ways to assign symbols to make sum of integers equal to target S
    """
    def find_target_sum_ways(self, nums: List[int], s: int) -> int:
        # Write your code here
        if sum(nums) < s:
            return 0

        dp = [0]
        for i in nums:
            tmp = []
            for j in dp:
                tmp.append(j + i)
                tmp.append(j - i)

            dp = tmp

        return dp.count(s)


# dfs
class Solution:
    """
    @param nums: the given array
    @param s: the given target
    @return: the number of ways to assign symbols to make sum of integers equal to target S
    """
    def find_target_sum_ways(self, nums: List[int], s: int) -> int:
        # Write your code here
        self.res = 0
        self.helper(nums, 0, s)

        return self.res

    def helper(self, nums, index, target):
        if index >= len(nums):
            if 0 == target:
                self.res += 1
            return

        self.helper(nums, index + 1, target - nums[index])
        self.helper(nums, index + 1, target + nums[index])