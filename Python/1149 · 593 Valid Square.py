from typing import (
    List,
)


class Solution:
    """
    @param p1: the first point
    @param p2: the second point
    @param p3: the third point
    @param p4: the fourth point
    @return: whether the four points could construct a square
    """

    def valid_square(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        # Write your code here
        p = [p1, p2, p3, p4]
        p.sort(key=lambda x: (x[0], x[1]))

        return (0 < self.length(p[0], p[1]) == self.length(p[0], p[2]) == self.length(p[2], p[3])
                == self.length(p[3], p[1])) and (0 < self.length(p[0], p[3]) == self.length(p[1], p[2]))  # tricky

    def length(self, p1, p2):
        return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2