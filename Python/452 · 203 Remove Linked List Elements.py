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
    @param head: a ListNode
    @param val: An integer
    @return: a ListNode
    """

    def remove_elements(self, head: ListNode, val: int) -> ListNode:
        # write your code here
        if not head:
            return None

        while head and val == head.val:  # tricky
            head = head.next

        node = head
        while node and node.next:  # tricky
            if val == node.next.val:
                node.next = node.next.next
            else:  # tricky
                node = node.next

        return head

# dummy node
class Solution:
    """
    @param head: a ListNode
    @param val: An integer
    @return: a ListNode
    """
    def remove_elements(self, head: ListNode, val: int) -> ListNode:
        # write your code here
        if not head:
            return None

        dummy = ListNode(0)
        dummy.next = head
        pre = dummy

        while head:
            if val == head.val:
                pre.next = head.next
                head = head.next
            else:
                pre = head
                head = head.next

        return dummy.next

