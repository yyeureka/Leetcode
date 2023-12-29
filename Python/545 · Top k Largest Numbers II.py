import heapq


class Solution:
    """
    @param: k: An integer
    """

    def __init__(self, k):
        # do intialization if necessary
        self.minheap = []
        self.k = k

    """
    @param: num: Number to be added
    @return: nothing
    """

    def add(self, num):
        # write your code here
        heapq.heappush(self.minheap, num)

        if len(self.minheap) > self.k:
            heapq.heappop(self.minheap)

    """
    @return: Top k element
    """

    def topk(self):
        # write your code here
        return sorted(self.minheap, reverse=True)


