from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: the root
    @param k: an integer
    @return: the value of the nearest leaf node to target k in the tree
    """

    def find_closest_leaf(self, root: TreeNode, k: int) -> int:
        # Write your code here
        if not root:
            return -1

        self.start = None
        parents = {}
        self.helper(root, k, parents)  # dfs find the parent of each node and the k node

        dq = collections.deque([self.start])
        visited = {self.start}  # key point

        while dq:
            node = dq.popleft()

            if not node.left and not node.right:
                return node.val

            if node.left and node.left not in visited:
                dq.append(node.left)
                visited.add(node.left)
            if node.right and node.right not in visited:
                dq.append(node.right)
                visited.add(node.right)
            if node in parents and parents[node] not in visited:  # tricky
                dq.append(parents[node])
                visited.add(parents[node])

        return -1

    def helper(self, root, k, parents):
        if k == root.val:
            self.start = root

        if root.left:
            parents[root.left] = root
            self.helper(root.left, k, parents)
        if root.right:
            parents[root.right] = root
            self.helper(root.right, k, parents)

