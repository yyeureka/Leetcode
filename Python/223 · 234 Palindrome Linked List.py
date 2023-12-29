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
    @param head: A ListNode.
    @return: A boolean.
    """
    def is_palindrome(self, head: ListNode) -> bool:
        # write your code here
        slow = head
        fast = head
        pre = None

        while fast and fast.next:
            fast = fast.next.next

            tmp = slow.next  # reverse the first half
            slow.next = pre
            pre = slow
            slow = tmp

        if fast:  # tricky odd
            slow = slow.next

        while slow or pre:
            if pre.val != slow.val:
                return False

            slow = slow.next
            pre = pre.next

        return True

