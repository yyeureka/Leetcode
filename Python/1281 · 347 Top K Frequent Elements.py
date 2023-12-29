from typing import (
    List,
)

import heapq

class Solution:
    """
    @param nums: the given array
    @param k: the given k
    @return: the k most frequent elements
             we will sort your return value in output
    """
    def top_k_frequent(self, nums: List[int], k: int) -> List[int]:
        # Write your code here
        count = {}
        minheap = []

        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1

        for num in count:
            heapq.heappush(minheap, (count[num], -num))

            if len(minheap) > k:
                heapq.heappop(minheap)

        res = []
        while minheap:
            _, num = heapq.heappop(minheap)
            res.append(-num)

        res.reverse()
        return res


