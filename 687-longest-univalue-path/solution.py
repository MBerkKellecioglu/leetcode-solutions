# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        
        ans = 0

        def dfs(node):
            nonlocal ans
            if not node:
                return None
   
            l = 0
            r = 0 

            if node.left: 
                l = dfs(node.left)

                if node.val == node.left.val:
                    l += 1
                else:
                    l = 0

            if node.right:
                r = dfs(node.right)

                if node.val == node.right.val:
                    r += 1
                else:
                    r = 0

            ans = max(ans, r + l)

            return max(l,r)

        dfs(root)

        return ans