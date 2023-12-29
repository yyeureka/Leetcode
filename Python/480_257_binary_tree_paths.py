from typing import (
    List,
)


class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: the root of the binary tree
    @return: all root-to-leaf paths
             we will sort your return value in output
    """
    def binary_tree_paths(self, root: TreeNode) -> List[str]:
        # write your code here
        if not root:
            return []
        
        res = []
        self.helper(root, "", res)

        return res

    def helper(self, root: TreeNode, path: str, res: List[str]):
        if not root:
            return
        
        path += "{}".format(root.val)

        if not root.left and not root.right:
            res.append(path)
            return
        if root.left:
            self.helper(root.left, path + "->", res)
        if root.right:
            self.helper(root.right, path + "->", res)

