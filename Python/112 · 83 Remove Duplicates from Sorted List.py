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
    @param head: head is the head of the linked list
    @return: head of linked list
    """

    def delete_duplicates(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        node = head
        while node and node.next:
            if node.val == node.next.val:
                node.next = node.next.next
            else:
                node = node.next

        return head


class Solution:
    """
    @param head: head is the head of the linked list
    @return: head of linked list
    """

    def delete_duplicates(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        dummy = ListNode(0)
        dummy.next = head
        pre = None

        while head:
            if pre and pre.val == head.val:
                pre.next = head.next
                head = head.next
            else:
                pre = head
                head = head.next

        return dummy.next