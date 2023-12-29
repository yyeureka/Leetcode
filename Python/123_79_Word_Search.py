from typing import (
    List,
)

# dfs
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return not word
        if not word:
            return True

        n = len(board)
        m = len(board[0])
        for i in range(n):
            for j in range(m):
                if word[0] != board[i][j]:
                    continue

                if self.dfs(board, i, j, word):
                    return True

        return False

    def dfs(self, board, i, j, word):
        if not word:
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j]:
            return False

        board[i][j] = '#'
        ret = self.dfs(board, i - 1, j, word[1:]) or self.dfs(board, i + 1, j, word[1:]) \
              or self.dfs(board, i, j - 1, word[1:]) or self.dfs(board, i, j + 1, word[1:])
        board[i][j] = word[0]

        return ret