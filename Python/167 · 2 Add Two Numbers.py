from lintcode import (
    ListNode,
)

# Iterative or recursive

"""
Definition of ListNode:
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param l1: the first list
    @param l2: the second list
    @return: the sum list of l1 and l2
    """
    def add_lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # write your code here
        dummy = ListNode(0)
        node = dummy
        carry = 0

        while l1 or l2 or carry > 0:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next

            node.next = ListNode(carry % 10)
            node = node.next
            carry //= 10

        return dummy.next


class Solution:
    """
    @param l1: the first list
    @param l2: the second list
    @return: the sum list of l1 and l2
    """
    def add_lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # write your code here
        return self.add(l1, l2, 0)

    def add(self, l1, l2, carry):
        if not l1 and not l2 and 0 == carry:
            return None

        if l1:
            carry += l1.val
            l1 = l1.next
        if l2:
            carry += l2.val
            l2 = l2.next

        node = ListNode(carry % 10)
        carry //= 10
        node.next = self.add(l1, l2, carry)
        return node
