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


# 1、inorder traversal，记录不符合顺序的两个node并交换，O(n)时间，O(1)空间
# 2、inorder traversal，排序了val后修改各node的val，O(nlogn)时间，O(n)空间
# 3、inorder traversal+bubble sort的思路，碰到不符合顺序的就两两交换，最差O(n^2)时间，O(n)空间


class Solution:
    """
    @param root: the given tree
    @return: the tree after swapping
    """

    def bst_swapped_node(self, root: TreeNode) -> TreeNode:
        # write your code here
        if not root:
            return None

        self.pre = None
        self.first = None
        self.second = None

        self.helper(root)
        if self.first:  # key point
            self.first.val, self.second.val = self.second.val, self.first.val

        return root

    def helper(self, root):
        if not root:
            return

        self.helper(root.left)

        if self.pre and self.pre.val > root.val:
            if not self.first:
                self.first = self.pre

            self.second = root  # key point 解决交换相邻两个node就完事的用例
        self.pre = root

        self.helper(root.right)


