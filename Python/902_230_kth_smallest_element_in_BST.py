
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: the given BST
    @param k: the given k
    @return: the kth smallest element in BST
    """
    def kth_smallest(self, root: TreeNode, k: int) -> int:
        # write your code here
        if not root:
            return -1
        
        cur = root
        nodes = []

        while cur or nodes:
            while cur:
                nodes.append(cur)
                cur = cur.left
            
            cur = nodes.pop()

            k -= 1
            if k <= 0:
                break
            
            cur = cur.right
        
        return cur.val