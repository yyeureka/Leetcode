from typing import (
    List,
)

# rainbow sort O(nlogk), O(logk)
# quick sort O(nlogn), O(logn)

class Solution:
    """
    @param colors: A list of integer
    @param k: An integer
    @return: nothing
    """

    def sort_colors2(self, colors: List[int], k: int):
        # write your code here
        self.sort(colors, 0, len(colors) - 1, 1, k)

    def sort(self, a, start, end, c_start, c_end):
        if start >= end or c_start >= c_end:
            return

        mid = (c_start + c_end) >> 1
        l, r = start, end

        while l <= r:
            while l <= r and a[l] <= mid:  # key point
                l += 1
            while l <= r and a[r] > mid:
                r -= 1
            if l <= r:
                a[l], a[r] = a[r], a[l]

        self.sort(a, start, r, c_start, mid)
        self.sort(a, l, end, mid + 1, c_end)
