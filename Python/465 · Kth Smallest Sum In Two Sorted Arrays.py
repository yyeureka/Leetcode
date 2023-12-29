from typing import (
    List,
)

# similar to #373

import heapq

class Solution:
    """
    @param a: an integer arrays sorted in ascending order
    @param b: an integer arrays sorted in ascending order
    @param k: An integer
    @return: An integer
    """
    def kth_smallest_sum(self, a: List[int], b: List[int], k: int) -> int:
        # write your code here
        if not a or not b:
            return None

        minheap = [(a[i] + b[0], i, 0) for i in range(min(k, len(a)))]

        while k > 0 and minheap:
            cur, l, r = heapq.heappop(minheap)

            if r < len(b) - 1:
                heapq.heappush(minheap, (a[l] + b[r + 1], l, r + 1))

            k -= 1

        return cur