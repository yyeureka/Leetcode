from typing import (
    List,
)

class Solution:
    """
    @param points: a 2D array
    @return: the number of boomerangs
    """
    def number_of_boomerangs(self, points: List[List[int]]) -> int:
        # Write your code here
        n = len(points)
        if not n:
            return 0

        res = 0
        for i in range(n):
            distances = {}
            for j in range(n):
                if i == j:
                    continue

                distance = self.get_distance(points[i], points[j])
                distances[distance] = distances.get(distance, 0) + 1

            for j in distances:
                res += distances[j] * (distances[j] - 1)  # key point

        return res

    def get_distance(self, p1, p2):
        return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2