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
    @param airplanes: An interval array
    @return: Count of airplanes are in the sky.
    """
    def count_of_airplanes(self, airplanes: List[Interval]) -> int:
        # write your code here
        points = []
        for i in airplanes:
            points.append((i.start, 1))
            points.append((i.end, -1))

        res = 0
        sum = 0
        points.sort()

        for _, cost in points:
            sum += cost

            if sum > res:
                res = sum

        return res
