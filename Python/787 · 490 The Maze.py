from typing import (
    List,
)


class Solution:
    """
    @param maze: the maze
    @param start: the start
    @param destination: the destination
    @return: whether the ball could stop at the destination
    """

    def has_path(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        # write your code here
        n = len(maze)
        m = len(maze[0])
        if not n or not m:
            return False

        dq = collections.deque([(start[0], start[1])])
        visited = {(start[0], start[1])}

        while dq:
            x, y = dq.popleft()

            if [x, y] == destination:
                return True

            for d_x, d_y in ((1, 0), (-1, 0), (0, -1), (0, 1)):
                xx = x  # tricky
                yy = y
                while 0 <= xx + d_x < n and 0 <= yy + d_y < m and 0 == maze[xx + d_x][yy + d_y]:  # 挑一个方向滚到底
                    xx += d_x
                    yy += d_y

                if (xx, yy) not in visited:
                    dq.append((xx, yy))
                    visited.add((xx, yy))

        return False



