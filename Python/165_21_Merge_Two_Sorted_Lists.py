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


# iterative
class Solution:
    """
    @param l1: ListNode l1 is the head of the linked list
    @param l2: ListNode l2 is the head of the linked list
    @return: ListNode head of linked list
    """

    def merge_two_lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # write your code here
        if not l1:
            return l2
        if not l2:
            return l1

        root = ListNode(0)
        node = root

        while l1 or l2:
            if not l2:
                node.next = l1
                l1 = l1.next
            elif not l1:
                node.next = l2
                l2 = l2.next
            elif l1.val < l2.val:
                node.next = l1
                l1 = l1.next
            else:
                node.next = l2
                l2 = l2.next

            node = node.next

        return root.next


# recursive
class Solution:
    """
    @param l1: ListNode l1 is the head of the linked list
    @param l2: ListNode l2 is the head of the linked list
    @return: ListNode head of linked list
    """

    def merge_two_lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # write your code here
        if not l1:
            return l2
        if not l2:
            return l1

        if l1.val < l2.val:
            l1.next = self.merge_two_lists(l1.next, l2)
            return l1
        else:
            l2.next = self.merge_two_lists(l1, l2.next)
            return l2
