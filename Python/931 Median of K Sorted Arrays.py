from typing import (
    List,
)


class Solution:
    """
    @param nums: the given k sorted arrays
    @return: the median of the given k sorted arrays
    """

    def find_median(self, nums: List[List[int]]) -> float:
        # write your code here
        if not nums or not nums[0]:
            return 0

        size = sum([len(num) for num in nums])
        if size & 1:
            return self.find_kth(nums, size // 2 + 1)
        return (self.find_kth(nums, size // 2) + self.find_kth(nums, size // 2 + 1)) / 2

    def find_kth(self, nums, k):
        i = min([num[0] for num in nums if num])
        j = max([num[-1] for num in nums if num])

        while i + 1 < j:
            mid = (i + j) // 2

            if self.count_smaller_equal(nums, mid) >= k:
                j = mid
            else:
                i = mid


        if self.count_smaller_equal(nums, i) >= k:
            return i
        return j

    def count_smaller_equal(self, nums, target):
        count = 0

        for num in nums:
            if not num:
                continue

            i = 0
            j = len(num) - 1

            while i + 1 < j:
                mid = (i + j) // 2

                if num[mid] > target:
                    j = mid
                else:
                    i = mid

            if num[i] > target:
                count += i
            elif num[j] > target:
                count += j
            else:
                count += j + 1

        return count