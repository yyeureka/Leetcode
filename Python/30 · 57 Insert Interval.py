from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    """
    @param intervals: Sorted interval list.
    @param new_interval: new interval.
    @return: A new interval list.
    """

    def insert(self, intervals: List[Interval], new_interval: Interval) -> List[Interval]:
        # write your code here
        if not intervals:  # tricky
            return [new_interval]

        if new_interval.start >= intervals[-1].start:
            intervals.append(new_interval)  # tricky
        else:
            for i in range(len(intervals)):
                if intervals[i].start > new_interval.start:
                    intervals.insert(i, new_interval)
                    break

        res = []
        for i in intervals:
            if not res or i.start > res[-1].end:
                res.append(i)
            else:
                res[-1].end = max(i.end, res[-1].end)

        return res







