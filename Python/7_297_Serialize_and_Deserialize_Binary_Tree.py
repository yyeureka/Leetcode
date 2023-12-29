# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return '#'

        dq = deque([root])
        res = ''

        while dq:
            node = dq.popleft()

            if node:
                res += str(node.val) + ','
                dq.append(node.left)
                dq.append(node.right)
            else:
                res += '#,'

        return res[:-1]

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if (not data) or ('#' == data[0]):
            return None

        vals = data.split(',')
        root = TreeNode(int(vals[0]))
        dq = deque([root])
        i = 1

        while dq and (i < len(vals)):
            node = dq.popleft()

            if '#' != vals[i]:
                node.left = TreeNode(int(vals[i]))
                dq.append(node.left)
            if '#' != vals[i + 1]:
                node.right = TreeNode(int(vals[i + 1]))
                dq.append(node.right)

            i += 2

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))