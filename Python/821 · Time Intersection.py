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
    @param seq_a: the list of intervals
    @param seq_b: the list of intervals
    @return: the time periods
    """

    def time_intersection(self, seq_a: List[Interval], seq_b: List[Interval]) -> List[Interval]:
        # Write your code here
        points = []

        for i in seq_a:
            points.append((i.start, 1))
            points.append((i.end, -1))
        for i in seq_b:
            points.append((i.start, 1))
            points.append((i.end, -1))

        points.sort()
        res = []
        online_user = 0
        start = None

        for i, j in points:
            online_user += j

            if 2 == online_user and not start:
                start = i
            elif online_user < 2 and start:
                res.append(Interval(start, i))
                start = None

        return res
