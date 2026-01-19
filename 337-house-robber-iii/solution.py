# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root):
            if not root:
                return [0, 0]

            l = dfs(root.left)
            r = dfs(root.right)
            
            return [max(root.val + r[1] + l[1], l[0] + r[0]), l[0] + r[0]]
        
        return max(dfs(root))