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
    @param l1: The first list.
    @param l2: The second list.
    @return: the sum list of l1 and l2.
    """

    def add_lists2(self, l1: ListNode, l2: ListNode) -> ListNode:
        # write your code here
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        dummy = ListNode(0)
        node = dummy
        carry = 0

        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next

            node.next = ListNode(carry % 10)
            node = node.next
            carry //= 10

        return self.reverse(dummy.next)

    def reverse(self, head):
        if not head:
            return None

        pre = None
        while head:
            tmp = head.next
            head.next = pre
            pre = head
            head = tmp

        return pre
