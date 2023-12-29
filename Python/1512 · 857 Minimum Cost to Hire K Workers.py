from typing import (
    List,
)

import heapq

class Solution:
    """
    @param quality: an array
    @param wage: an array
    @param k: an integer
    @return: the least amount of money needed to form a paid group
    """
    def mincost_to_hire_workers(self, quality: List[int], wage: List[int], k: int) -> float:
        # Write your code here
        workers = sorted([(w / q, q) for q, w in zip(quality, wage)])  # increasing wage/quality ratio

        res = float('inf')
        sum = 0
        maxheap = []

        for r, q in workers:
            heapq.heappush(maxheap, -q)
            sum += q

            if len(maxheap) > k:
                sum += heapq.heappop(maxheap)

            if k == len(maxheap):
                res = min(res, r * sum)  # k smallest quality of worker 0~i, ratio i * sum(quality)

        return res