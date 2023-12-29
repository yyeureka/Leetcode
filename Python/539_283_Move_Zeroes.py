from typing import (
    List,
)

class Solution:
    """
    @param nums: an integer array
    @return: nothing
    """
    def move_zeroes(self, nums: List[int]):
        # write your code here
        length = len(nums)
        fast = 0
        slow = 0

        while slow < length:
            if fast >= length:
                nums[slow] = 0
                slow += 1
            else:
                if 0 == nums[fast]:
                    fast += 1
                else:
                    nums[slow] = nums[fast]
                    slow += 1
                    fast += 1


class Solution:
    """
    @param nums: an integer array
    @return: nothing
    """

    def move_zeroes(self, nums: List[int]):
        # write your code here
        i = 0
        for num in nums:
            if 0 == num:
                continue

            nums[i] = num
            i += 1
        for j in range(i, len(nums)):
            nums[j] = 0
            j += 1