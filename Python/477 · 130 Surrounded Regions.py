from collections import deque

# bfs:
# 先检查4个border，如果有O，将O和附近的O置为#
# 将所有的O变为X，将#变为O
#
# union-find：
# 将边界O连接到dummy, 连接O及周围的O
# 未连接到dummy的O可以变为X


DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# bfs
class Solution:
    """
    @param: board: board a 2D board containing 'X' and 'O'
    @return: nothing
    """

    def surroundedRegions(self, board):
        # write your code here
        if not board or not board[0]:
            return

        n = len(board)
        m = len(board[0])
        dq = deque()

        for j in range(m):
            if 'O' == board[0][j]:
                dq.append((0, j))
            if 'O' == board[n - 1][j]:
                dq.append((n - 1, j))
        for i in range(1, n - 1):  # tricky
            if 'O' == board[i][0]:
                dq.append((i, 0))
            if 'O' == board[i][m - 1]:
                dq.append((i, m - 1))

        while dq:
            i, j = dq.pop()
            board[i][j] = '#'

            for delta_i, delta_j in DIRECTIONS:
                next_i = i + delta_i
                next_j = j + delta_j

                if next_i < 0 or next_i >= n or next_j < 0 or next_j >= m or 'O' != board[next_i][next_j]:  # tricky
                    continue

                dq.append((next_i, next_j))

        for i in range(n):
            for j in range(m):
                if 'O' == board[i][j]:
                    board[i][j] = 'X'
                elif '#' == board[i][j]:  # tricky
                    board[i][j] = 'O'


# union find
class UF:
    def __init__(self, n):
        self.v = [i for i in range(n)]
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

    def check(self, p, q):
        return self.get_root(p) == self.get_root(q)


class Solution:
    """
    @param: board: board a 2D board containing 'X' and 'O'
    @return: nothing
    """

    def surroundedRegions(self, board):
        # write your code here
        if not board or not board[0]:
            return

        n = len(board)
        m = len(board[0])
        uf = UF(n * m + 1)

        for i in range(n):
            for j in range(m):
                if 'X' == board[i][j]:
                    continue

                if 0 == i or (n - 1) == i or 0 == j or (m - 1) == j:
                    uf.quick_union(i * m + j, n * m)
                else:
                    if 'O' == board[i - 1][j]:
                        uf.quick_union(i * m + j, (i - 1) * m + j)
                    if 'O' == board[i + 1][j]:
                        uf.quick_union(i * m + j, (i + 1) * m + j)
                    if 'O' == board[i][j - 1]:
                        uf.quick_union(i * m + j, i * m + (j - 1))
                    if 'O' == board[i][j + 1]:
                        uf.quick_union(i * m + j, i * m + (j + 1))

        for i in range(n):
            for j in range(m):
                if 'O' == board[i][j] and not uf.check(i * m + j, n * m):
                    board[i][j] = 'X'