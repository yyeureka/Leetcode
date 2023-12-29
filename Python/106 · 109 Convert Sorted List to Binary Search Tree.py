from lintcode import (
    ListNode,
    TreeNode,
)

# 将linked list转化为vector
# 直接对linked list进行操作

"""
Definition of ListNode:
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param head: The first node of linked list
    @return: a tree node
    """

    def sorted_list_to_b_s_t(self, head: ListNode) -> TreeNode:
        # write your code here
        if not head:
            return None

        nodes = []
        while head:
            nodes.append(head.val)
            head = head.next

        return self.convert(nodes, 0, len(nodes) - 1)

    def convert(self, nodes, start, end):
        if start > end:
            return None
        if start == end:
            return TreeNode(nodes[start])

        mid = (start + end) // 2
        root = TreeNode(nodes[mid])
        root.left = self.convert(nodes, start, mid - 1)
        root.right = self.convert(nodes, mid + 1, end)

        return root


class Solution:
    """
    @param head: The first node of linked list
    @return: a tree node
    """

    def sorted_list_to_b_s_t(self, head: ListNode) -> TreeNode:
        # write your code here
        if not head:
            return None

        length = self.get_length(head)
        root, next = self.convert(head, length)  # 把从head开始长为length的node转化为bst，返回root和从head开始length+1的node
        return root

    def get_length(self, head):
        length = 0
        while head:
            head = head.next
            length += 1

        return length

    def convert(self, head, length):
        if 0 == length:
            return None, head  # key point
        if 1 == length:
            return TreeNode(head.val), head.next

        left, mid = self.convert(head, length // 2)
        right, next = self.convert(mid.next, length - length // 2 - 1)  # key point, exclude mid node

        root = TreeNode(mid.val)
        root.left = left
        root.right = right

        return root, next
