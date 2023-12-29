from typing import (
    List,
)

# 1、二分：O(log(min(m, n)))
#    长为n的A有0~n共n+1中划分法(BS的l和r) 以i划分(BS的mid)：
#    A[0],A[1]...A[i-1] | A[i]...A[n-1]
#    B[0],B[1]...B[j-1] | B[j]...B[m-1]
#    median的定义：
#    a.左右两部分相等：i+j=n-i+m-j+1(奇数的median放左边)=>j=(n+m+1)/2-i
#    b.左max<=右min:
#    若A[i-1]>B[j],则i太大应往左移
#    若B[j-1]>A[i],则i应往右移
#    else即为找到，odd时为max(A[i-1],B[j-1]),even时为min(A[i],B[j])和max(A[i-1],B[j-1])的均值
# 2、找第k小方法：O(log(m + n))
#    A、B分别取0~k/2-1个元素
#    如A[k/2-1]>B[k/2-1],即第k小不在B中,从A的0开始和B的k/2开始找第k-k/2小——哪个小丢哪个的数


class Solution:
    """
    @param a: An integer array
    @param b: An integer array
    @return: a double whose format is *.5 or *.0
    """
    def find_median_sorted_arrays(self, a: List[int], b: List[int]) -> float:
        # write your code here
        if len(a) > len(b):
            return self.find_median_sorted_arrays(b, a)  # split on the shorter list

        n = len(a)
        m = len(b)
        left = 0
        right = n  # key point

        while left <= right:
            i = (left + right) // 2
            j = (n + m + 1) // 2 - i

            left_a = left_b = float('-inf')
            right_a = right_b = float('inf')

            if i > 0:
                left_a = a[i - 1]
            if i < n:
                right_a = a[i]
            if j > 0:
                left_b = b[j - 1]
            if j < m:
                right_b = b[j]

            if left_a > right_b:
                right = i - 1
            elif left_b > right_a:
                left = i + 1
            else:
                if (n + m) & 1:
                    return max(left_a, left_b)

                return (max(left_a, left_b) + min(right_a, right_b)) / 2


class Solution:
    """
    @param a: An integer array
    @param b: An integer array
    @return: a double whose format is *.5 or *.0
    """
    def find_median_sorted_arrays(self, a: List[int], b: List[int]) -> float:
        # write your code here
        size = len(a) + len(b)

        if size & 1:
            return self.find_k(a, 0, b, 0, int(size / 2) + 1)
        else:
            return (self.find_k(a, 0, b, 0, int(size / 2)) + self.find_k(a, 0, b, 0, int(size / 2) + 1)) / 2

    def find_k(self, a, ia, b, ib, k):
        if ia >= len(a):
            return b[ib + k - 1]
        if ib >= len(b):
            return a[ia + k - 1]
        if 1 == k:
            return min(a[ia], b[ib])

        half_k = int(k / 2)

        if ia + half_k - 1 >= len(a):
            return self.find_k(a, ia, b, ib + half_k, k - half_k)
        elif ib + half_k - 1 >= len(b):
            return self.find_k(a, ia + half_k, b, ib, k - half_k)
        elif a[ia + half_k - 1] > b[ib + half_k - 1]:
            return self.find_k(a, ia, b, ib + half_k, k - half_k)
        else:
            return self.find_k(a, ia + half_k, b, ib, k - half_k)