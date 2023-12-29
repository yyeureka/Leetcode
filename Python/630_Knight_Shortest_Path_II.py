# bfs, the same as lint611

from typing import (
    List,
)

from collections import deque

DIRECTIONS = [(1, 2), (-1, 2), (2, 1), (-2, 1)]

class Solution:
    """
    @param grid: a chessboard included 0 and 1
    @return: the shortest path
    """
    def shortest_path2(self, grid: List[List[bool]]) -> int:
        # write your code here
        if not grid or 1 == grid[0][0] or 1 == grid[-1][-1]:
            return -1

        res = 0
        dq = deque([(0, 0)])
        grid[0][0] = 1  # key point

        while dq:
            size = len(dq)

            for i in range(size):
                x, y = dq.popleft()

                if len(grid) - 1 == x and len(grid[0]) - 1 == y:
                    return res

                for delta_x, delta_y in DIRECTIONS:
                    next_x = x + delta_x
                    next_y = y + delta_y

                    if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]) or 1 == grid[next_x][next_y]:
                        continue

                    dq.append((next_x, next_y))
                    grid[next_x][next_y] = 1  # key point

            res += 1

        return -1