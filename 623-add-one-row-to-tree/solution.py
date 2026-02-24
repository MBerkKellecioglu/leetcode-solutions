# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:

        if depth == 1:
            return TreeNode(val, root)
    

        def dfs(root, d):
            if not root:
                return None

            if d == depth - 1:
                root.left = TreeNode(val, root.left)
                root.right = TreeNode(val, None, root.right)
                return None

            dfs(root.left, d + 1)
            dfs(root.right, d + 1)

            return None
        
        dfs(root, 1)
        
        return root
        
