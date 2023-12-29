from typing import (
    List,
)

from collections import deque


class Solution:
    """
    @param grid: a list of list
    @param k: an integer
    @return: Return the minimum number of steps to walk
    """

    def shortest_path(self, grid: List[List[int]], k: int) -> int:
        # write your code here
        if not grid or not grid[0]:
            return 0

        m = len(grid)
        n = len(grid[0])
        dq = deque([(0, 0, k)])
        visited = set((0, 0, k))
        step = 0

        while dq:
            size = len(dq)

            for i in range(size):
                x, y, cnt = dq.popleft()

                if (x == m - 1) and (y == n - 1):
                    return step

                for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    x_ = x + dx
                    y_ = y + dy
                    if x_ < 0 or x_ >= m or y_ < 0 or y_ >= n:
                        continue

                    if 1 == grid[x_][y_]:
                        cnt_ = cnt - 1
                    else:
                        cnt_ = cnt
                    if cnt_ < 0 or (x_, y_, cnt_) in visited:
                        continue

                    dq.append((x_, y_, cnt_))
                    visited.add((x_, y_, cnt_))

            step += 1

        return -1