import random

class RandomizedSet:
    
    def __init__(self):
        # do intialization if necessary
        self.vals = []
        self.indexes = {}

    """
    @param: val: a value to the set
    @return: true if the set did not already contain the specified element or false
    """
    def insert(self, val):
        # write your code here
        if val in self.indexes:
            return False

        self.indexes[val] = len(self.vals)
        self.vals.append(val)
        return True

    """
    @param: val: a value from the set
    @return: true if the set contained the specified element or false
    """
    def remove(self, val):
        # write your code here
        if val not in self.indexes:
            return False
        
        index = self.indexes[val]
        last = self.vals[-1]
        self.vals[index] = last
        self.indexes[last] = index  # triky
        self.vals.pop()
        self.indexes.pop(val)

        return True

    """
    @return: Get a random element from the set
    """
    def getRandom(self):
        # write your code here
        return self.vals[random.randint(0, len(self.vals) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param = obj.insert(val)
# param = obj.remove(val)
# param = obj.getRandom()