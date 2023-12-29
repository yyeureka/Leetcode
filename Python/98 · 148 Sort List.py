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
    @param head: The head of linked list.
    @return: You should return the head of the sorted linked list, using constant space complexity.
    """
    def sort_list(self, head: ListNode) -> ListNode:
        # write your code here
        if not head or not head.next:  # key point
            return head

        fast = head.next  # key point
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        mid = slow.next
        slow.next = None  # key point
        return self.merge(self.sort_list(head), self.sort_list(mid))

    def merge(self, left, right):
        if not left:
            return right
        if not right:
            return left
        if left.val < right.val:
            left.next = self.merge(left.next, right)
            return left
        else:
            right.next = self.merge(left, right.next)
            return right
