import heapq

class Solution:
    """
    @param val: a num from the data stream.
    @return: nothing
    """
    def __init__(self):
        self.smaller = []  # maxheap
        self.larger = []   # minheap

    def add(self, val: int):
        # write your code here
        heapq.heappush(self.smaller, -val)
        heapq.heappush(self.larger, -heapq.heappop(self.smaller))

        while len(self.smaller) < len(self.larger):
            heapq.heappush(self.smaller, -heapq.heappop(self.larger))

    """
    @return: return the median of the all numbers
    """
    def getMedian(self) -> int:
        # write your code here
        return -self.smaller[0]
