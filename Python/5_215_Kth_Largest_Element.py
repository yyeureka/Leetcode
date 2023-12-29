# quick select - O(n)
# heap O(nlogk)
# sort O(nlogn)

from typing import (
    List,
)


class Solution:
    """
    @param k: An integer
    @param nums: An array
    @return: the Kth largest element
    """

    def kth_largest_element(self, k: int, nums: List[int]) -> int:
        # write your code here
        if not nums or k < 1 or k > len(nums):
            return None

        return self.partition(nums, 0, len(nums) - 1, k)

    def partition(self, nums, start, end, k):
        if start >= end:
            return nums[k - 1]

        l, r = start, end
        pivot = nums[(start + end) // 2]

        while l <= r:
            while l <= r and nums[l] > pivot:
                l += 1
            while l <= r and nums[r] < pivot:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        if r >= k - 1:
            return self.partition(nums, start, r, k)
        if l <= k - 1:
            return self.partition(nums, l, end, k)
        return nums[k - 1]


# heap
import heapq
class Solution:
    """
    @param k: An integer
    @param nums: An array
    @return: the Kth largest element
    """
    def kth_largest_element(self, k: int, nums: List[int]) -> int:
        # write your code here
        minheap = []

        for i in nums:
            heapq.heappush(minheap, i)

            if len(minheap) > k:
                heapq.heappop(minheap)

        return heapq.heappop(minheap)