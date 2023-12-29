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


class UF:
    def __init__(self, n):
        self.count = 0
        self.v = [-1 for i in range(n)]
        self.sz = [1 for i in range(n)]

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
    @param n: An integer
    @param m: An integer
    @param operators: an array of point
    @return: an integer array
    """

    def num_islands2(self, n: int, m: int, operators: List[Point]) -> List[int]:
        # write your code here
        if not operators:
            return []

        uf = UF(n * m)
        res = []

        for p in operators:
            id = p.x * m + p.y
            if uf.v[id] < 0:  # tricky 会有重复的点
                uf.v[id] = id
                uf.count += 1

                for d_x, d_y in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    x = p.x + d_x
                    y = p.y + d_y
                    if x < 0 or x >= n or y < 0 or y >= m or uf.v[x * m + y] < 0:
                        continue

                    uf.quick_union(id, x * m + y)

            res.append(uf.count)  # tricky 重复的点也需要加进res

        return res