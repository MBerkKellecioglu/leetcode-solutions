# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
    
        def dfs(root, val):
            if root is None:
                return 0

            val = (val << 1) | root.val
            
            if not root.left and not root.right:
                return val

            sum1 = dfs(root.left, val)
            sum2 = dfs(root.right, val)

            return sum1 + sum2

        return dfs(root, 0)

        return ans