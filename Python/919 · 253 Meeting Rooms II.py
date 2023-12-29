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
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """

    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here
        points = []

        for i in intervals:
            points.append((i.start, 1))
            points.append((i.end, -1))

        points.sort()
        res = 0
        ongoing_meetings = 0

        for _, cost in points:
            ongoing_meetings += cost

            if ongoing_meetings > res:
                res = ongoing_meetings

        return res
