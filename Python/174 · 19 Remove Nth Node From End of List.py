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
    @return: The head of linked list.
    """

    def remove_nth_from_end(self, head: ListNode, n: int) -> ListNode:
        # write your code here
        if not head or n <= 0:
            return None

        dummy = ListNode(0)
        dummy.next = head
        fast = head
        slow = dummy

        while n > 0:
            fast = fast.next
            n -= 1
        while fast:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next

        return dummy.next
