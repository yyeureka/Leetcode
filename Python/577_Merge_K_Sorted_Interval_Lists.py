# heap
# merge sort

"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

import heapq


class Solution:
    """
    @param intervals: the given k sorted interval lists
    @return:  the new sorted interval list
    """

    def mergeKSortedIntervalLists(self, intervals):
        # write your code here
        if not intervals:
            return []

        heap = []
        res = []

        for i in intervals:
            for j in i:
                heapq.heappush(heap, (j.start, j.end))

        while heap:
            x, y = heapq.heappop(heap)

            if not res or x > res[-1].end:
                res.append(Interval(x, y))
            elif y > res[-1].end:
                res[-1].end = y

        return res


class Solution:
    """
    @param intervals: the given k sorted interval lists
    @return:  the new sorted interval list
    """

    def mergeKSortedIntervalLists(self, intervals):
        # write your code here
        if not intervals:
            return []

        return self.merge(intervals, 0, len(intervals) - 1)

    def merge(self, intervals, start, end):
        if end <= start:
            return intervals[start]

        mid = (start + end) // 2
        left = self.merge(intervals, start, mid)
        right = self.merge(intervals, mid + 1, end)

        res = []
        i = 0
        j = 0

        while i < len(left) or j < len(right):
            if i >= len(left):
                cur = right[j]
                j += 1
            elif j >= len(right):
                cur = left[i]
                i += 1
            elif left[i].start == right[j].start:
                cur = left[i]
                cur.end = max(left[i].end, right[j].end)
                i += 1
                j += 1
            elif left[i].start < right[j].start:
                cur = left[i]
                i += 1
            else:
                cur = right[j]
                j += 1

            if not res or cur.start > res[-1].end:
                res.append(cur)
            elif cur.end > res[-1].end:
                res[-1].end = cur.end

        return res



