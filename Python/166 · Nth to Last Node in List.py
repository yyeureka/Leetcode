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
    @param head: The first node of linked list.
    @param n: An integer
    @return: Nth to last node of a singly linked list.
    """
    def nth_to_last(self, head: ListNode, n: int) -> ListNode:
        # write your code here
        if not head:
            return None

        fast = head
        slow = head
        while n > 0:
            fast = fast.next
            n -= 1
        while fast:
            fast = fast.next
            slow = slow.next

        return slow
