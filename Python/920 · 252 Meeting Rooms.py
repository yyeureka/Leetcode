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


# sort
class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """

    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        # Write your code here
        intervals.sort(key=lambda x: (x.start, x.end))

        for i in range(1, len(intervals)):
            if intervals[i].start < intervals[i - 1].end:
                return False

        return True



# sweep line
class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """
    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        # Write your code here
        points = []
        for i in intervals:
            points.append((i.start, 1))
            points.append((i.end, -1))

        points.sort()
        ongoing_meetings = 0

        for _, cost in points:
            ongoing_meetings += cost
            if ongoing_meetings > 1:
                return False

        return True