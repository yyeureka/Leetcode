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
    @param head: The first node of linked list
    @param n: the start index
    @param m: the end node
    @return: A ListNode
    """
    def delete_node(self, head: ListNode, n: int, m: int) -> ListNode:
        # Write your code here
        if n < 0 or n > m:
            return head

        dummy = ListNode(0)
        dummy.next = head

        pre = dummy
        node = head
        for i in range(n):
            if not node:
                return head

            pre = pre.next
            node = node.next
        for i in range(n, m):
            if not node:
                return head

            node = node.next

        pre.next = node.next

        return dummy.next
