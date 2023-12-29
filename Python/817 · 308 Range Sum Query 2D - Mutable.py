# binary indexed tree
# 原matrix：
# [[3,0,1,4,2],
#  [5,6,3,2,1],
#  [1,2,0,1,5],
#  [4,1,0,1,7],
#  [1,0,3,0,5]]
# tree matrix：
# [[3, 3, 1,8, 2], 3,3+0,1,3+0+1+4,2
#  [8, 14,4,24,3], 5+3,6+0+5+3,3+1，...
#  [1, 3, 0,4, 5],
#  [13,22,4,34,15],
#  [1, 1, 3,4, 5]]
#
# sumRegion(2,1,4,3)为sum(4,3)-sum(4,0)-sum(1,3)+sum(1,0)


class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        if not matrix or not matrix[0]:
            return

        n = len(matrix)
        m = len(matrix[0])
        self.bit = [[0 for j in range(m + 1)] for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                for k in range(i, i - (i & (-i)), -1):
                    for l in range(j, j - (j & (-j)), -1):
                        self.bit[i][j] += matrix[k - 1][l - 1]

    def update(self, row, col, val):
        """
        :type row: int
        :type col: int
        :type val: int
        :rtype: void
        """
        diff = val - self.sumRegion(row, col, row, col)  # key point

        i = row + 1
        while i < len(self.bit):
            j = col + 1  # key point
            while j < len(self.bit[0]):
                self.bit[i][j] += diff
                j += j & (-j)

            i += i & (-i)

    def sumPrefix(self, row, col):
        sum = 0

        i = row + 1
        while i > 0:
            j = col + 1  # key point
            while j > 0:
                sum += self.bit[i][j]
                j -= j & (-j)

            i -= i & (-i)

        return sum

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.sumPrefix(row2, col2) + self.sumPrefix(row1 - 1, col1 - 1) \
               - self.sumPrefix(row2, col1 - 1) - self.sumPrefix(row1 - 1, col2)  # key point


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)