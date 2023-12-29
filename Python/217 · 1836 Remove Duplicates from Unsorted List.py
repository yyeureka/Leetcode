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
    @return: Head node.
    """
    def remove_duplicates(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        hash = set()
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy

        while head:
            if head.val in hash:
                pre.next = head.next
                head = head.next
            else:
                hash.add(head.val)
                pre = head
                head = head.next

        return dummy.next


class Solution:
    """
    @param head: The first node of linked list.
    @return: Head node.
    """
    def remove_duplicates(self, head: ListNode) -> ListNode:
        # write your code here
        if not head:
            return None

        hash = set([head.val])

        node = head
        while node and node.next:
            if node.next.val in hash:
                node.next = node.next.next
            else:
                hash.add(node.next.val)
                node = node.next

        return head

