from typing import (
    List,
)

import heapq

class Solution:
    """
    @param nums: A list of integers
    @param k: An integer
    @return: The median of the element inside the window at each moving
    """
    def median_sliding_window(self, nums: List[int], k: int) -> List[int]:
        # write your code here
        smaller = []  # maxheap
        larger = []   # minheap
        res = []

        for i in range(len(nums)):
            heapq.heappush(smaller, -nums[i])
            heapq.heappush(larger, -heapq.heappop(smaller))

            if i >= k:
                if nums[i - k] <= -smaller[0]:
                    smaller.remove(-nums[i - k])
                    heapq.heapify(smaller)
                else:
                    larger.remove(nums[i - k])
                    heapq.heapify(larger)

            while len(smaller) < len(larger):
                heapq.heappush(smaller, -heapq.heappop(larger))

            if i >= k - 1:
                res.append(-smaller[0])

        return res

