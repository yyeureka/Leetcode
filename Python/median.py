import heapq


class Solution:
    def __init__(self):
        self.smaller = []  # maxheap
        self.larger = []   # minheap

    def add(self, val: int):
        # write your code here
        heapq.heappush(self.smaller, -val)
        heapq.heappush(self.larger, -heapq.heappop(self.smaller))

        while len(self.smaller) < len(self.larger):
            heapq.heappush(self.smaller, -heapq.heappop(self.larger))

    def getMedian(self) -> int:
        # write your code here
        return -self.smaller[0]


# partition
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