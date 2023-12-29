# Inorder
def inorder_traversal(self, root: TreeNode) -> List[int]:
    # write your code here
    if not root:
        return []

    res = []
    stack = []

    while root or stack:
        while root:
            stack.append(root)
            root = root.left

        root = stack.pop()
        res.append(root.val)

        root = root.right

    return res


# Preorder
def preorder_traversal(self, root: TreeNode) -> List[int]:
    # write your code here
    if not root:
        return []

    res = []
    stack = []

    while root or stack:
        while root:
            res.append(root.val)
            stack.append(root)
            root = root.left

        root = stack.pop()

        root = root.right

    return res


# Postorder
def postorder_traversal(self, root: TreeNode) -> List[int]:
    # write your code here
    if not root:
        return []

    res = []
    stack = []

    while root or stack:
        while root:
            res.append(root.val)
            stack.append(root)
            root = root.right

        root = stack.pop()

        root = root.left

    return res[::-1]