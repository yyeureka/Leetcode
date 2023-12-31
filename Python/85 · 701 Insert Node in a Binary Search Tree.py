"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param: root: The root of the binary search tree.
    @param: node: insert this node into the binary search tree
    @return: The root of the new binary search tree.
    """
    def insertNode(self, root, node):
        # write your code here
        if not root:
            return node

        head = root

        while head:
            if head.val > node.val:
                if head.left:
                    head = head.left
                else:
                    head.left = node
                    break
            else:
                if head.right:
                    head = head.right
                else:
                    head.right = node
                    break

        return root


class Solution:
    """
    @param: root: The root of the binary search tree.
    @param: node: insert this node into the binary search tree
    @return: The root of the new binary search tree.
    """

    def insertNode(self, root, node):
        # write your code here
        if not root:
            return node

        if root.val > node.val:
            root.left = self.insertNode(root.left, node)
        else:
            root.right = self.insertNode(root.right, node)

        return root
