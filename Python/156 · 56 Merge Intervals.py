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
    @param intervals: interval list.
    @return: A new interval list.
    """
    def merge(self, intervals: List[Interval]) -> List[Interval]:
        # write your code here
        intervals.sort(key=lambda x: x.start)
        res = []

        for i in intervals:
            if not res or i.start > res[-1].end:
                res.append(i)
            else:
                res[-1].end = max(i.end, res[-1].end)

        return res

