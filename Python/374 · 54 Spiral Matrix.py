from typing import (
    List,
)


class Solution:
    """
    @param matrix: a matrix of m x n elements
    @return: an integer list
    """

    def spiral_order(self, matrix: List[List[int]]) -> List[int]:
        # write your code here
        if not matrix or not matrix[0]:
            return []

        up = 0
        down = len(matrix) - 1
        left = 0
        right = len(matrix[0]) - 1
        direction = 0
        res = []

        while left <= right and up <= down:
            if 0 == direction:
                for j in range(left, right + 1):
                    res.append(matrix[up][j])

                up += 1
            elif 1 == direction:
                for i in range(up, down + 1):
                    res.append(matrix[i][right])

                right -= 1
            elif 2 == direction:
                for j in range(right, left - 1, -1):
                    res.append(matrix[down][j])

                down -= 1
            else:
                for i in range(down, up - 1, -1):
                    res.append(matrix[i][left])

                left += 1

            direction = (direction + 1) % 4

        return res
