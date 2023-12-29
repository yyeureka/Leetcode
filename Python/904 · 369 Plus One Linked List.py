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
    @param head: the first Node
    @return: the answer after plus one
    """

    def plus_one(self, head: ListNode) -> ListNode:
        # Write your code here
        if not head:
            return None

        head = self.reverse(head)

        carry = 1
        pre = None
        node = head
        while node:
            cur = node.val + carry
            node.val = cur % 10
            carry = cur // 10

            pre = node
            node = node.next

        if carry > 0:
            pre.next = ListNode(carry)

        return self.reverse(head)

    def reverse(self, head):
        pre = None

        while head:
            tmp = head.next
            head.next = pre
            pre = head
            head = tmp

        return pre


