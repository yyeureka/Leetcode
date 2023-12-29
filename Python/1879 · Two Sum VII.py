from typing import (
    List,
)

# hash better time
# 2 pointers better memory, complicated


# hash
class Solution:
    """
    @param nums: the input array
    @param target: the target number
    @return: return the target pair
             we will sort your return value in output
    """
    def two_sum_v_i_i(self, nums: List[int], target: int) -> List[List[int]]:
        # write your code here
        if not nums:
            return []

        res = []
        num = {}

        for i in range(len(nums)):
            if target - nums[i] in num:
                res.append([num[target - nums[i]], i])

            num[nums[i]] = i

        return res


# 2 pointers
class Solution:
    """
    @param nums: the input array
    @param target: the target number
    @return: return the target pair
             we will sort your return value in output
    """

    def two_sum_v_i_i(self, nums: List[int], target: int) -> List[List[int]]:
        # write your code here
        if not nums:
            return []

        res = []
        left = 0  # minimum
        right = 0  # maximum

        for i in range(len(nums)):
            if nums[i] < nums[left]:
                left = i
            if nums[i] > nums[right]:
                right = i

        while nums[left] < nums[right] and left >= 0 and right >= 0:
            if target == nums[left] + nums[right]:
                if left < right:  # key point
                    res.append([left, right])
                else:
                    res.append([right, left])

                left = self.nextLeft(left, nums)
                right = self.nextRight(right, nums)

            elif nums[left] + nums[right] < target:
                left = self.nextLeft(left, nums)
            else:
                right = self.nextRight(right, nums)

        return res

    def nextLeft(self, left, nums):
        if nums[left] < 0:  # negative with smaller abs or smallest non-negative
            for i in range(left - 1, -1, -1):
                if nums[i] < 0:
                    return i
            for i in range(len(nums)):
                if nums[i] >= 0:
                    return i
            return -1
        else:  # larger positive
            for i in range(left + 1, len(nums)):
                if nums[i] > 0:
                    return i
            return -1

    def nextRight(self, right, nums):
        if nums[right] > 0:  # smaller non-negative or negative with smallest abs
            for i in range(right - 1, -1, -1):
                if nums[i] >= 0:
                    return i
            for i in range(len(nums)):
                if nums[i] < 0:
                    return i
            return -1
        else:  # smaller negative
            for i in range(right + 1, len(nums)):
                if nums[i] < 0:
                    return i
            return -1