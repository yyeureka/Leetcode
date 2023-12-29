# bfs
# dfs + memo

from typing import (
    List,
)
from lintcode import (
    Point,
)

"""
Definition for a point:
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
"""

from collections import deque

DIRECTIONS = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]

# bfs
class Solution:
    """
    @param grid: a chessboard included 0 (false) and 1 (true)
    @param source: a point
    @param destination: a point
    @return: the shortest path
    """
    def shortest_path(self, grid: List[List[bool]], source: Point, destination: Point) -> int:
        # write your code here
        if not grid or 1 == grid[source.x][source.y] or 1 == grid[destination.x][destination.y]:
            return -1
        if source == destination:
            return 0

        res = 0
        dq = deque([source])
        grid[source.x][source.y] = 1  # key point

        while dq:
            size = len(dq)

            for i in range(size):
                cur = dq.popleft()

                if cur.x == destination.x and cur.y == destination.y:  # cannot use cur == destination
                    return res

                for delta_x, delta_y in DIRECTIONS:
                    next_x = cur.x + delta_x
                    next_y = cur.y + delta_y

                    if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]) or 1 == grid[next_x][next_y]:
                        continue

                    dq.append(Point(next_x, next_y))
                    grid[next_x][next_y] = 1  # key point

            res += 1

        return -1


# dfs + memo
INF = 0x3f3f3f3f

class Solution:
    """
    @param grid: a chessboard included 0 (false) and 1 (true)
    @param source: a point
    @param destination: a point
    @return: the shortest path
    """
    def shortest_path(self, grid: List[List[bool]], source: Point, destination: Point) -> int:
        # write your code here
        if not grid or 1 == grid[source.x][source.y] or 1 == grid[destination.x][destination.y]:
            return -1
        if source == destination:
            return 0

        n = len(grid)
        m = len(grid[0])
        length = {}

        self.dfs(grid, source, destination, length)

        if INF == length[source]:
            return -1
        return length[source]

    def dfs(self, grid, src, dst, length):
        if src in length:
            return
        if src == dst:
            length[src] = 0
            return

        length[src] = INF

        for delta_x, delta_y in DIRECTIONS:
            next_x = src.x + delta_x
            next_y = src.y + delta_y

            if next_x < 0 or next_x >= len(grid) or next_y < 0 or next_y >= len(grid[0]) or 1 == grid[next_x][next_y]:
                continue

            next = Point(next_x, next_y)
            self.dfs(grid, next, dst, length)

            if length[next] + 1 < length[src]:
                length[src] = length[next] + 1





