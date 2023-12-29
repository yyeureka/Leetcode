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
    @param list1: one of the given list
    @param list2: another list
    @return: the new sorted list of interval
    """

    def merge_two_interval(self, list1: List[Interval], list2: List[Interval]) -> List[Interval]:
        # write your code here
        if not list1:
            return list2
        if not list2:
            return list1

        res = []
        i, j = 0, 0
        n1, n2 = len(list1), len(list2)

        while i < n1 or j < n2:
            if i >= n1:
                cur = list2[j]
                j += 1
            elif j >= n2:
                cur = list1[i]
                i += 1
            elif list1[i].start > list2[j].start:
                cur = list2[j]
                j += 1
            else:
                cur = list1[i]
                i += 1

            if len(res) > 0 and cur.start <= res[-1].end:
                if cur.end > res[-1].end:
                    res[-1].end = cur.end
            else:
                res.append(cur)

        return res


# leetcode 56
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals

        intervals.sort(key=lambda x: (x[0], x[1]))

        res = []

        for i in intervals:
            if not res or i[0] > res[-1][1]:
                res.append(i)
            elif i[1] > res[-1][1]:
                res[-1][1] = i[1]

        return res