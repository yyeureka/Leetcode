class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.next = None


class LRUCache:
    """
    @param: capacity: An integer
    """

    def __init__(self, capacity):
        # do intialization if necessary
        self.head = Node(0, 0)  # LRU node
        self.tail = self.head   # FRU node
        self.cache = {}         # key: pre node
        self.capacity = capacity
        self.size = 0

    """
    @param: key: An integer
    @return: An integer
    """

    def get(self, key):
        # write your code here
        if key not in self.cache:
            return -1

        pre = self.cache[key]
        cur = pre.next
        self.popNode(pre)
        self.addNode(cur)

        return cur.val

    """
    @param: key: An integer
    @param: value: An integer
    @return: nothing
    """

    def set(self, key, value):
        # write your code here
        if self.get(key) > 0:  # key point
            self.cache[key].next.val = value
            return

        if self.size == self.capacity:
            self.popNode(self.head)
        self.addNode(Node(key, value))

    def popNode(self, pre):
        cur = pre.next
        pre.next = cur.next
        if cur.next:
            self.cache[cur.next.key] = pre  # tricky
        else:
            self.tail = pre  # tricky

        self.cache.pop(cur.key)
        self.size -= 1

    def addNode(self, cur):
        cur.next = None
        self.cache[cur.key] = self.tail  # tricky
        self.tail.next = cur
        self.tail = cur  # tricky
        self.size += 1

