class Solution:
    """
    @param: A: sorted integer array A which has m elements, but size of A is m+n
    @param: m: An integer
    @param: B: sorted integer array B which has n elements
    @param: n: An integer
    @return: nothing
    """

    def mergeSortedArray(self, A, m, B, n):
        # write your code here
        i = m - 1
        j = n - 1
        k = (m + n) - 1  # 3 pointers, start from the end

        while k >= 0:
            if j < 0:
                break
            elif i < 0:
                A[k] = B[j]
                j -= 1
            elif A[i] > B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1

            k -= 1