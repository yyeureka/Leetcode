# 1D
class NumArray:
    def __init__(self, nums):
        n = len(nums)
        self.bit = [0 for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(i, i - (i & (-i)), -1):
                self.bit[i] += nums[j - 1]

    def update(self, i, val):
        diff = val - self.sumRange(i, i)
        i += 1

        while i < len(self.bit):
            self.bit[i] += diff
            i += i & (-i)

    def sumPrefix(self, i):  # 0~i
        sum = 0
        i += 1

        while i > 0:
            sum += self.bit[i]
            i -= i & (-i)

        return sum

    def sumRange(self, i, j):  # i~j
        return self.sumPrefix(j) - self.sumPrefix(i - 1)


# 2D
class NumMatrix(object):
    def __init__(self, matrix):
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
        return self.sumPrefix(row2, col2) + self.sumPrefix(row1 - 1, col1 - 1) \
               - self.sumPrefix(row2, col1 - 1) - self.sumPrefix(row1 - 1, col2)  # key point