"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
Definition for singly-linked list.
class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
"""

from collections import deque


class Solution:
    # @param {TreeNode} root the root of binary tree
    # @return {ListNode[]} a lists of linked list
    def binaryTreeToLists(self, root):
        # Write your code here
        if not root:
            return []

        dq = deque([root])
        res = []

        while dq:
            size = len(dq)
            head = ListNode(0)
            p = head  # key point

            for i in range(size):
                node = dq.popleft()
                p.next = ListNode(node.val)  # key point
                p = p.next  # key point

                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

            res.append(head.next)  # key point

        return res