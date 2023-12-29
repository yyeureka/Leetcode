class Solution:
    """
    @param A: the run-length encoded sequence
    """

    def __init__(self, A):
        # do some initialization if necessary
        self.A = A
        self.index = 0

    """
    @param n: the number of elements to exhaust
    @return: exhausts the next n elements and returns the last element exhausted 
    """

    def next(self, n):
        # write your code here
        while n > 0:
            if self.index >= len(self.A):
                return -1

            if self.A[self.index] >= n:
                self.A[self.index] -= n
                return self.A[self.index + 1]
            else:
                n -= self.A[self.index]
                self.index += 2