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

# 注意！不是从上到下的一条path，而是parent-child关系，能一条直线连接的path
# recursive pre-order traversal：
# 对每一个node，node、node+左子树、node+右子树、node+左子树+右子树最大值，更新res
# 返回node、node+左子树、node+右子树最大值，注意！这里只能选一条子树！

class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def max_path_sum(self, root: TreeNode) -> int:
        # write your code here
        if not root:
            return 0

        self.res = float('-inf')
        self.helper(root)

        return self.res

    def helper(self, root):
        if not root:
            return 0

        left = max(0, self.helper(root.left))
        right = max(0, self.helper(root.right))

        sum = root.val + left + right
        if sum > self.res:
            self.res = sum

        return root.val + max(left, right)
