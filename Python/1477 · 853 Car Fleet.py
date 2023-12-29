from typing import (
    List,
)


class Solution:
    """
    @param target: the target
    @param position: the initial position
    @param speed: the speed
    @return: How many car fleets will arrive at the destination
    """

    def car_fleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Write your code here
        p_t = {}
        for p, s in zip(position, speed):
            p_t[p] = (target - p) / s

        position.sort(reverse=True)
        res = 0
        front = None
        for p in position:
            if not front or p_t[p] > front:
                res += 1
                front = p_t[p]

        return res

