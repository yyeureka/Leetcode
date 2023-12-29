from typing import (
    List,
)

# quick select O(n)
# maxheap O(nlogk)

import heapq


class Solution:
    """
    @param k: An integer
    @param nums: An integer array
    @return: kth smallest element
    """
    def kth_smallest(self, k: int, nums: List[int]) -> int:
        # write your code here
        return self.partition(nums, 0, len(nums) - 1, k)

    def partition(self, nums, start, end, k):
        if start >= end:
            return nums[k - 1]

        l, r = start, end
        pivot = nums[(start + end) // 2]

        while l <= r:
            while l <= r and nums[l] < pivot:
                l += 1
            while l <= r and nums[r] > pivot:
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


class Solution:
    """
    @param k: An integer
    @param nums: An integer array
    @return: kth smallest element
    """
    def kth_smallest(self, k: int, nums: List[int]) -> int:
        # write your code here
        maxheap = []

        for i in nums:
            heapq.heappush(maxheap, -i)

            if len(maxheap) > k:
                heapq.heappop(maxheap)

        return -heapq.heappop(maxheap)