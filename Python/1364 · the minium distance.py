from typing import (
    List,
)

from collections import deque

# check both index and gate


class Solution:
    """
    @param maze_map: a 2D grid
    @return: return the minium distance
    """

    def get_min_distance(self, maze_map: List[List[int]]) -> int:
        # write your code here
        n = len(maze_map)
        m = len(maze_map[0])
        if not n or not m:
            return -1

        dq = deque()
        visited = set()
        visited_num = set()  # gate visited
        num_to_idx = {}  # gate: indexes
        distance = 0

        for i in range(n):
            for j in range(m):
                if -2 == maze_map[i][j]:
                    visited.add((i, j))
                    dq.append((i, j))
                elif -3 == maze_map[i][j]:
                    end = (i, j)
                elif maze_map[i][j] > 0:
                    if maze_map[i][j] in num_to_idx:
                        num_to_idx[maze_map[i][j]].add((i, j))
                    else:
                        num_to_idx[maze_map[i][j]] = {(i, j)}

        while dq:
            size = len(dq)
            for i in range(size):
                x, y = dq.popleft()

                if end == (x, y):
                    return distance

                for x_, y_ in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):  # check index
                    if x_ < 0 or x_ >= n or y_ < 0 or y_ >= m or -1 == maze_map[x_][y_] or (x_, y_) in visited:
                        continue

                    visited.add((x_, y_))
                    dq.append((x_, y_))

                if maze_map[x][y] <= 0 or maze_map[x][y] in visited_num:
                    continue
                visited_num.add(maze_map[x][y])  # key point

                for x_, y_ in num_to_idx[maze_map[x][y]]:
                    if (x_, y_) in visited:  # key point
                        continue

                    visited.add((x_, y_))
                    dq.append((x_, y_))

            distance += 1

        return -1

