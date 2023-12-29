# 1D max
def max_sub_array(self, nums: List[int]) -> int:
    # write your code here
    if not nums:
        return 0

    res = nums[0]
    sum = 0  # prefix sum
    min = 0  # min prefix sum

    for num in nums:
        sum += num

        if sum - min > res:
            res = sum - min

        if sum < min:
            min = sum

    return res


# 1D sum
def subarray_sum(self, nums: List[int]) -> List[int]:
    # write your code here
    if not nums:
        return []

    n = len(nums)
    sum = 0
    prefix_sum = {0: -1}  # key point, prefix sum: index

    for i in range(n):
        sum += nums[i]

        if sum in prefix_sum:
            return [prefix_sum[sum] + 1, i]

        prefix_sum[sum] = i

    return []


# 2D max
def max_submatrix(self, matrix: List[List[int]]) -> int:
    # write your code here
    if not matrix or not matrix[0]:  # tricky
        return 0

    n = len(matrix)
    m = len(matrix[0])
    prefix = [[0 for j in range(m)] for i in range(n + 1)]  # prefix sum of each column
    res = float('-inf')

    for i in range(n):
        for j in range(m):
            prefix[i + 1][j] = prefix[i][j] + matrix[i][j]

    for up in range(n):
        for down in range(up + 1, n + 1):
            sum = 0                  # prefix sum of up~down-1, 0~j
            min_sum = 0              # min prefix sum of up~down-1, 0~j

            for j in range(m):
                sum += prefix[down][j] - prefix[up][j]
                if sum - min_sum > res:
                    res = sum - min_sum
                if sum < min_sum:
                    min_sum = sum

    return res


# 2D sum
def submatrix_sum(self, matrix: List[List[int]]) -> List[List[int]]:
    # write your code here
    if not matrix or not matrix[0]:
        return [[]]

    n = len(matrix)
    m = len(matrix[0])
    prefix = [[0 for j in range(m)] for i in range(n + 1)]

    for i in range(n):
        for j in range(m):
            prefix[i + 1][j] = prefix[i][j] + matrix[i][j]

    for up in range(n):
        for down in range(up + 1, n + 1):
            sum = 0
            pre = {0: -1}  # key point!

            for j in range(m):
                sum += prefix[down][j] - prefix[up][j]

                if sum in pre:
                    return [[up, pre[sum] + 1], [down - 1, j]]  # key point!

                if sum not in pre:
                    pre[sum] = j

    return [[]]