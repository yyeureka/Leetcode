from typing import (
    List,
)


class Solution:
    """
    @param nums: An integer array
    @return: nothing
    """

    def recover_rotated_sorted_array(self, nums: List[int]):
        # write your code here
        if len(nums) <= 1:
            return
        if nums[0] < nums[-1]:
            return

        i = 0
        j = len(nums) - 1

        while i + 1 < j:
            if nums[i] < nums[j]:
                break

            mid = (i + j) // 2

            if nums[i] == nums[mid]:
                i += 1
            elif nums[i] < nums[mid]:
                i = mid
            else:
                j = mid

        if nums[i] < nums[j]:
            offset = i
        else:
            offset = j
        nums[:] = nums[offset:] + nums[:offset]

        # def reverse(s, i, j):
        #     while i < j:
        #         s[i], s[j] = s[j], s[i]
        #         i += 1
        #         j -= 1

        # reverse(nums, 0, offset - 1)
        # reverse(nums, offset, len(nums) - 1)
        # reverse(nums, 0, len(nums) - 1)


