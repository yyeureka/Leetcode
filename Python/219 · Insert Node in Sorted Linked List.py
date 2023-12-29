from lintcode import (
    ListNode,
)

"""
Definition of ListNode:
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param head: The head of linked list.
    @param val: An integer.
    @return: The head of new linked list.
    """
    def insert_node(self, head: ListNode, val: int) -> ListNode:
        # write your code here
        dummy = ListNode(0)
        dummy.next = head

        node = dummy
        while node.next and node.next.val <= val:
            node = node.next

        tmp = node.next
        node.next = ListNode(val)
        node.next.next = tmp

        return dummy.next
