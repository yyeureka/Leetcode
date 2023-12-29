"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    """
    @param hashTable: A list of The first node of linked list
    @return: A list of The first node of linked list which have twice size
    """

    def rehashing(self, hashTable):
        # write your code here
        size = len(hashTable)
        size *= 2
        res = [None for i in range(size)]

        for node in hashTable:
            p = node
            while p:
                pos = p.val % size
                if res[pos]:
                    q = res[pos]
                    while q.next:
                        q = q.next
                    q.next = ListNode(p.val)  # tricky
                else:
                    res[pos] = ListNode(p.val)

                p = p.next

        return res