"""
Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
"""
from collections import deque


class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    def copyRandomList(self, head):
        # write your code here
        if not head:
            return None

        node = {head: RandomListNode(head.label)}
        dq = deque([head])

        while dq:
            cur = dq.pop()

            if cur.next:
                if cur.next not in node:
                    node[cur.next] = RandomListNode(cur.next.label)
                    dq.append(cur.next)

                node[cur].next = node[cur.next]

            if cur.random:
                if cur.random not in node:
                    node[cur.random] = RandomListNode(cur.random.label)
                    dq.append(cur.random)

                node[cur].random = node[cur.random]

        return node[head]


class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    def copyRandomList(self, head):
        # write your code here
        if not head:
            return None

        cpy = RandomListNode(head.label)
        node = {head: cpy}

        cur = head
        while cur:
            cpy.random = cur.random

            if cur.next:
                cpy.next = RandomListNode(cur.next.label)
                node[cur.next] = cpy.next

            cur = cur.next
            cpy = cpy.next

        cpy = node[head]
        while cpy:
            if cpy.random:
                cpy.random = node[cpy.random]

            cpy = cpy.next

        return node[head]