from typing import (
    List,
)


class Solution:
    """
    @param nums: an array containing n + 1 integers which is between 1 and n
    @return: the duplicate one
    """

    def find_duplicate(self, nums: List[int]) -> int:
        # write your code here
        hash = set()

        for i in nums:
            if i in hash:
                return i

            hash.add(i)


class Solution:
    """
    @param nums: an array containing n + 1 integers which is between 1 and n
    @return: the duplicate one
    """

    def find_duplicate(self, nums: List[int]) -> int:
        # write your code here
        n = len(nums)
        i = 0

        while i < n:
            while nums[i] != i + 1 and 0 < nums[i] < n and nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                nums[i] = nums[tmp - 1]
                nums[tmp - 1] = tmp

            i += 1

        for i in range(n):
            if nums[i] != i + 1:
                return nums[i]
