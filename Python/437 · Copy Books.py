from typing import (
    List,
)

class Solution:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copy_books(self, pages: List[int], k: int) -> int:
        # write your code here
        if not pages or k <= 0:
            return 0

        start, end = max(pages), sum(pages)
        while start + 1 < end:
            mid = (start + end) // 2

            if self.count(pages, mid) <= k:  # tricky
                end = mid
            else:
                start = mid

        if self.count(pages, start) <= k:  # tricky
            return start
        return end

    def count(self, pages, max_time):
        k = 1
        time = 0

        for page in pages:
            if time + page > max_time:
                k += 1
                time = 0

            time += page

        return k
