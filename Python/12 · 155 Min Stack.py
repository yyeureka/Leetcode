# 1. stack and minStack
# 2. stack and min


class MinStack:
    def __init__(self):
        # do intialization if necessary
        self.stack = []
        self.minStack = []

    """
    @param: number: An integer
    @return: nothing
    """

    def push(self, number):
        # write your code here
        self.stack.append(number)

        if not self.minStack or number <= self.minStack[-1]:  # key point
            self.minStack.append(number)

    """
    @return: An integer
    """

    def pop(self):
        # write your code here
        res = self.stack.pop()

        if res == self.minStack[-1]:
            self.minStack.pop()

        return res

    """
    @return: An integer
    """

    def min(self):
        # write your code here
        return self.minStack[-1]


class MinStack:
    def __init__(self):
        # do intialization if necessary
        self.minVal = float('inf')
        self.stack = []

    """
    @param: number: An integer
    @return: nothing
    """

    def push(self, number):
        # write your code here
        if number <= self.minVal:  # key point
            self.stack.append(self.minVal)
            self.minVal = number

        self.stack.append(number)

    """
    @return: An integer
    """

    def pop(self):
        # write your code here
        res = self.stack.pop()

        if self.minVal == res:
            self.minVal = self.stack.pop()

        return res

    """
    @return: An integer
    """

    def min(self):
        # write your code here
        return self.minVal
