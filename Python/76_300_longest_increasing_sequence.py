from typing import (
    List,
)

class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longest_increasing_subsequence(self, nums: List[int]) -> int:
        # write your code here
        LIS = []

        for i in nums:
            if not LIS or i > LIS[-1]:
                LIS.append(i)
            else:
                self.insert(LIS, i)

        return len(LIS)

    def insert(self, LIS, num):
        i = 0
        j = len(LIS) - 1

        while i + 1 < j:
            mid = (i + j) // 2

            if LIS[mid] >= num:
                j = mid
            else:
                i = mid

        if LIS[i] >= num:
            LIS[i] = num
        else:
            LIS[j] = num


class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longest_increasing_subsequence(self, nums: List[int]) -> int:
        # write your code here
        n = len(nums)
        if n <= 1:
            return n
        
        dp = [1] * n
        LIS = 1

        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i] and dp[j] >= dp[i]:
                    dp[i] = dp[j] + 1
                    
            LIS = max(LIS, dp[i])
        
        return LIS
