from collections import deque

class MyStack:

    def __init__(self):
        self.queue = deque([])
        

    def push(self, x: int) -> None:
        self.queue.append(x)
        

    def pop(self) -> int:
        size = len(self.queue)
        
        while size > 1:
            self.queue.append(self.queue.popleft())
            size -= 1
        
        return self.queue.popleft()   
        

    def top(self) -> int:
        res = self.pop()
        self.queue.append(res)
        
        return res  
        

    def empty(self) -> bool:
        return not self.queue


# List
# class MyStack:

#     def __init__(self):
#         self.queue = []
        

#     def push(self, x: int) -> None:
#         self.queue.append(x)
        

#     def pop(self) -> int:
#         if self.empty():
#             return -1
        
#         size = len(self.queue)
#         while size > 1:
#             self.queue.append(self.queue.pop(0)) # O(n)
#             size -= 1
        
#         res = self.queue.pop(0)
        
#         return res

        
#     def top(self) -> int:
#         if self.empty():
#             return -1
        
#         return self.queue[-1]
        

#     def empty(self) -> bool:
#         return not self.queue


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()