from typing import (
    List,
)

# 轮流走棋, X先手, 所以棋盘中X的数量一定与O的数量相同或比它多1个
# 只能有其中一人达到了胜利状态, 并且达到胜利状态的人一定是刚刚走过棋的

class Solution:
    """
    @param board: the given board
    @return: True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game
    """
    def valid_tic_tac_toe(self, board: List[str]) -> bool:
        # Write your code
        if not board or not board[0]:
            return False

        count_x = 0
        count_o = 0
        for i in range(3):
            for j in range(3):
                if 'X' == board[i][j]:
                    count_x += 1
                elif 'O' == board[i][j]:
                    count_o += 1

        if (count_x > count_o + 1) or (count_o > count_x):
            return False

        for i in range(3):  # check each row
            if board[i][0] == board[i][1] == board[i][2]:
                if 'X' == board[i][0]:
                    return count_x == count_o + 1
                elif 'O' == board[i][0]:
                    return count_x == count_o
        for j in range(3):  # check each col
            if board[0][j] == board[1][j] == board[2][j]:
                if 'X' == board[0][j]:
                    return count_x == count_o + 1
                elif 'O' == board[0][j]:
                    return count_x == count_o
        if board[0][0] == board[1][1] == board[2][2]:
            if 'X' == board[0][0]:
                return count_x == count_o + 1
            elif 'O' == board[0][0]:
                return count_x == count_o
        if board[0][2] == board[1][1] == board[2][0]:
            if 'X' == board[0][2]:
                return count_x == count_o + 1
            elif 'O' == board[0][2]:
                return count_x == count_o

        return True
