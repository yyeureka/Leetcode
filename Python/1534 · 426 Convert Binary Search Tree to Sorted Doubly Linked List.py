"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

from collections import deque


class Solution:
    """
    @param root: root of a tree
    @return: head node of a doubly linked list
    """

    def treeToDoublyList(self, root):
        # Write your code here.
        dq = deque()
        head = None
        tail = None
        pre = None

        while root or dq:
            while root:
                dq.append(root)
                root = root.left

            root = dq.pop()

            if not head:
                head = root
            tail = root

            if pre:
                pre.right = root
                root.left = pre
            pre = root

            root = root.right

        head.left = tail
        tail.right = head

        return head
