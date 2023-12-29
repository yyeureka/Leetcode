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
    @param head: n
    @return: The new head of reversed linked list.
    """
    def reverse(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        pre = None
        while head:
            tmp = head.next
            head.next = pre
            pre = head
            head = tmp

        return pre
