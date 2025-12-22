# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        ans = 0

        def dfs(root, s):
            nonlocal ans

            if not root:
                return
            
            if root.left == None and root.right == None:
                s += str(root.val)
                ans += int(s)
                return

            dfs(root.left, s + str(root.val))
            dfs(root.right, s + str(root.val))
        
        dfs(root, "")

        return ans