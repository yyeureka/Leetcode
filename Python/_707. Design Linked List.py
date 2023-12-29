class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class MyLinkedList:
    def __init__(self):
        self.head = Node(0)
        self.tail = Node(0)
        self.head.next = self.tail  # key point
        self.size = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1

        node = self.head
        while index >= 0:
            node = node.next
            index -= 1
        return node.val

    def addAtHead(self, val: int) -> None:
        self.head.val = val
        tmp = Node(0)
        tmp.next = self.head
        self.head = tmp
        self.size += 1

    def addAtTail(self, val: int) -> None:
        self.tail.val = val
        self.tail.next = Node(0)
        self.tail = self.tail.next  # tricky
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        if 0 == index:
            return self.addAtHead(val)
        if self.size == index:
            return self.addAtTail(val)

        node = self.head
        while index > 0:
            node = node.next
            index -= 1

        tmp = Node(val)
        tmp.next = node.next
        node.next = tmp
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return

        node = self.head
        while index > 0:
            node = node.next
            index -= 1

        node.next = node.next.next
        self.size -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)