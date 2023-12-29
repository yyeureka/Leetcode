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
    @param head: ListNode head is the head of the linked list
    @param m: An integer
    @param n: An integer
    @return: The head of the reversed ListNode
    """
    def reverse_between(self, head: ListNode, m: int, n: int) -> ListNode:
        # write your code here
        if not head:
            return None

        dummy = ListNode(0)
        dummy.next = head
        pre = dummy  # m前的元素

        for i in range(1, m):
            pre = head
            head = head.next

        for i in range(m, n):  # 把cur后的元素放到pre后
            tmp = head.next.next
            head.next.next = pre.next
            pre.next = head.next
            head.next = tmp

        return dummy.next


class Solution:
    """
    @param head: ListNode head is the head of the linked list
    @param m: An integer
    @param n: An integer
    @return: The head of the reversed ListNode
    """
    def reverse_between(self, head: ListNode, m: int, n: int) -> ListNode:
        # write your code here
        if not head:
            return None

        dummy = ListNode(0)
        dummy.next = head
        node = dummy  # m前的元素

        for i in range(1, m):
            node = head
            head = head.next

        pre = head
        head = head.next
        for i in range(m, n):
            tmp = head.next
            head.next = pre
            pre = head
            head = tmp

        node.next.next = head
        node.next = pre

        return dummy.next