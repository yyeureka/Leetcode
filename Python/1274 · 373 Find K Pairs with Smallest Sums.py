from typing import (
    List,
)

import heapq

class Solution:
    """
    @param nums1: List[int]
    @param nums2: List[int]
    @param k: an integer
    @return: return List[List[int]]
    """
    def k_smallest_pairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        # write your code here
        if not nums1 or not nums2:
            return []

        res = []
        heap = [(nums1[i] + nums2[0], i, 0) for i in range(min(k, len(nums1)))]

        while len(res) < k and heap:
            _, l, r = heapq.heappop(heap)
            res.append([nums1[l], nums2[r]])

            if r + 1 < len(nums2):
                heapq.heappush(heap, (nums1[l] + nums2[r + 1], l, r + 1))

        return res


class Solution:
    """
    @param nums1: List[int]
    @param nums2: List[int]
    @param k: an integer
    @return: return List[List[int]]
    """
    def k_smallest_pairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        # write your code here
        if not nums1 or not nums2:
            return []

        res = []
        heap = []
        hash = set()
        heapq.heappush(heap, (nums1[0] + nums2[0], 0, 0))

        while len(res) < k and heap:
            _, l, r = heapq.heappop(heap)
            res.append([nums1[l], nums2[r]])

            if l + 1 < len(nums1) and (l + 1, r) not in hash:
                heapq.heappush(heap, (nums1[l + 1] + nums2[r], l + 1, r))
                hash.add((l + 1, r))
            if r + 1 < len(nums2) and (l, r + 1) not in hash:
                heapq.heappush(heap, (nums1[l] + nums2[r + 1], l, r + 1))
                hash.add((l, r + 1))

        return res
