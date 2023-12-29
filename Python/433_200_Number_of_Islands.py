from collections import deque

# BFS
# DFS 深度过大的时候有stack overflow风险
# Union find
# 1. traverse all nodes, treat all 1 as a Union
# 2. traverse all nodes, quickUnion adjacent 1
# 3. return the number of union

from typing import (
    List,
)

# BFS
DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # key point

class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def num_islands(self, grid: List[List[bool]]) -> int:
        # write your code here
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])
        res = 0

        for i in range(n):
            for j in range(m):
                if (0 == grid[i][j]):
                    continue

                res += 1
                self.bfs(i, j, grid)
        
        return res

    def bfs(self, i, j, grid):
        dq = deque([(i, j)])  # tricky
        grid[i][j] = 0  # key point

        while dq:
            i, j = dq.popleft()  # key point
            
            for delta_i, delta_j in DIRECTIONS:
                next_i = i + delta_i
                next_j = j + delta_j

                if (next_i < 0) or (next_i >= len(grid)) or (next_j < 0) or (next_j >= len(grid[0])) or (0 == grid[next_i][next_j]):
                    continue
                
                dq.append((next_i, next_j))
                grid[next_i][next_j] = 0  # key point

# DFS
class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def num_islands(self, grid: List[List[bool]]) -> int:
        # write your code here
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])
        res = 0

        for i in range(n):
            for j in range(m):
                if (0 == grid[i][j]):
                    continue

                res += 1
                self.traverse(i, j, grid)
        
        return res

    def traverse(self, i, j, grid):
        n = len(grid)
        m = len(grid[0])
        if (i < 0) or (i >= n) or (j < 0) or (j >= m) or (0 == grid[i][j]):
            return

        grid[i][j] = 0
        self.traverse(i - 1, j, grid)
        self.traverse(i, j - 1, grid)
        self.traverse(i + 1, j, grid)
        self.traverse(i, j + 1, grid)


# union find
class UF:
    def __init__(self, grid, n, m):
        self.count = 0
        self.v = []
        self.sz = []

        for i in range(n):
            for j in range(m):
                if 1 == grid[i][j]:
                    self.count += 1

                self.v.append(i * m + j)
                self.sz.append(1)

    def get_root(self, i):
        while i != self.v[i]:
            self.v[i] = self.v[self.v[i]]
            i = self.v[i]

        return i

    def quick_union(self, p, q):
        i = self.get_root(p)
        j = self.get_root(q)
        if i == j:
            return

        if self.sz[i] < self.sz[j]:
            self.v[i] = j
            self.sz[j] += self.sz[i]
        else:
            self.v[j] = i
            self.sz[i] += self.sz[j]
        self.count -= 1


class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """

    def num_islands(self, grid: List[List[bool]]) -> int:
        # write your code here
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])
        uf = UF(grid, n, m)

        for i in range(n):
            for j in range(m):
                if (0 == grid[i][j]):
                    continue

                if i > 0 and 1 == grid[i - 1][j]:
                    uf.quick_union(i * m + j, (i - 1) * m + j)
                if i < n - 1 and 1 == grid[i + 1][j]:
                    uf.quick_union(i * m + j, (i + 1) * m + j)
                if j > 0 and 1 == grid[i][j - 1]:
                    uf.quick_union(i * m + j, i * m + j - 1)
                if j < m - 1 and 1 == grid[i][j + 1]:
                    uf.quick_union(i * m + j, i * m + j + 1)

        return uf.count
        
