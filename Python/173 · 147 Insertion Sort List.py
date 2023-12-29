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
    @return: The head of linked list.
    """

    def insertion_sort_list(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        dummy = ListNode(0)

        while head:
            node = dummy

            while node.next and node.next.val <= head.val:
                node = node.next

            tmp1 = node.next
            tmp2 = head.next
            node.next = head
            head.next = tmp1
            head = tmp2

        return dummy.next
