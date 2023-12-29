Description = '''
给一个二维的矩阵，包含 'X' 和 'O', 找到所有被 'X' 围绕的区域，并用 'X' 替换其中所有的 'O'
输入:
  X X X X
  X O O X
  X X O X
  X O X X
输出: 
  X X X X
  X X X X
  X X X X
  X O X X
'''


def traverse(board, i_idx, j_idx):
    row = len(board)
    col = len(board[0])
    if board[i_idx][j_idx] == 'X':
        return False

    if i_idx == 0 or i_idx == row - 1 or j_idx == 0 or j_idx == col - 1:
        return True

    status = traverse(board, i_idx - 1, j_idx)\
             or traverse(board, i_idx + 1, j_idx)\
             or traverse(board, i_idx, j_idx - 1)\
             or traverse(board, i_idx, j_idx + 1)

    if not status:
        # board[i_idx] = board[i_idx].replace(board[i_idx][j_idx], 'O', 1)
        s1 = list(board[i_idx])
        s1[j_idx] = 'X'
        board[i_idx] = ''.join(s1)
        return False
    else:
        return True


class Solution:
    """
    @param: board: board a 2D board containing 'X' and 'O'
    @return: nothing
    """
    def surroundedRegions(self, board):
        if board:
            row = len(board)
            col = len(board[0])

            for i in range(row):
                for j in range(col):
                    if board[i][j] == 'O':
                        traverse(board, i, j)


board = ["XXXX","XOOX","XXOO","XOXX"]
s = Solution()
s.surroundedRegions(board)
print(board)
