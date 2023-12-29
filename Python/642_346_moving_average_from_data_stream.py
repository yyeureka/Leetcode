from collections import deque

class MovingAverage(object):
    """
    @param: size: An integer
    """
    def __init__(self, size):
        # do intialization if necessary
        self.queue = deque([])
        self.size = size
        self.sum = 0

    """
    @param: val: An integer
    @return:  
    """
    def next(self, val):
        # write your code here
        self.queue.append(val)
        self.sum += val

        if len(self.queue) > self.size:
            self.sum -= self.queue.popleft()
        
        return self.sum / len(self.queue)


# List
# class MovingAverage(object):
#     """
#     @param: size: An integer
#     """
#     def __init__(self, size):
#         # do intialization if necessary
#         self.data = []
#         self.size = size
#         self.sum = 0

#     """
#     @param: val: An integer
#     @return:  
#     """
#     def next(self, val):
#         # write your code here
#         self.data.append(val)
#         self.sum += val

#         length = len(self.data)

#         if length > self.size:
#             self.sum -= self.data[length - self.size - 1]  # O(n)!
        
#         return self.sum / min(self.size, length)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param = obj.next(val)