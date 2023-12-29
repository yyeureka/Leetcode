"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

Example of iterate a tree:
iterator = BSTIterator(root)
while iterator.hasNext():
    node = iterator.next()
    do something for node 
"""


class BSTIterator:
    """
    @param: root: The root of binary tree.
    """
    def __init__(self, root):
        # do intialization if necessary
        self.cur = root
        self.nodes = []
      
    """
    @return: True if there has next node, or false
    """
    def hasNext(self):
        # write your code here
        return self.cur or self.nodes

    """
    @return: return next node
    """
    def _next(self):
        # write your code here
        if not self.hasNext():
            return None
        
        while self.cur:
            self.nodes.append(self.cur)
            self.cur = self.cur.left

        res = self.nodes.pop()
        self.cur = res.right

        return res
