from typing import (
    List,
)

# Diff of sum O(n), O(1): sum(0~n+1) - sum(nums)
# XOR O(n), O(1): a^b^b = a, nums没有少的时候序号0~i ^ 数值0~i为0
# Set O(n), O(n)
# sort + 2 pointers O(nlogn), O(logn)
# 2 pointers: place numbers in the right position, the largest number n in the missing position


# Diff
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """
    def find_missing(self, nums: List[int]) -> int:
        # write your code here
        n = len(nums)
        diff = int(n * (n + 1) / 2)

        for num in nums:
            diff -= num

        return diff


# XOR
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """

    def find_missing(self, nums: List[int]) -> int:
        # write your code here
        res = 0
        i = 0
        while i < len(nums):
            res ^= i ^ nums[i]
            i += 1

        return res ^ i


# Set
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """

    def find_missing(self, nums: List[int]) -> int:
        # write your code here
        s = set(nums)
        n = len(nums)

        for i in range(n):
            if i not in s:
                return i

        return n


# sort + 2 pointers
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """

    def find_missing(self, nums: List[int]) -> int:
        # write your code here
        nums.sort()
        n = len(nums)

        for i in range(n):
            if nums[i] != i:
                return i

        return n


# 2 pointers
class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """

    def find_missing(self, nums: List[int]) -> int:
        # write your code here
        i = 0
        n = len(nums)

        while i < n:  # place numbers in the right position, the largest number n in the missing position
            while nums[i] != i and 0 <= nums[i] < n and nums[nums[i]] != nums[i]:  # swap nums[nums[i]] and nums[i]
                tmp = nums[i]
                nums[i] = nums[tmp]
                nums[tmp] = tmp
            i += 1

        for i in range(n):
            if nums[i] != i:
                return i

        return n