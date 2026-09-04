# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        
        prev = float("-inf")

        ans = float("inf")

        def dfs(root):
            nonlocal prev
            nonlocal ans

            if not root:
                return None

            dfs(root.left)

            ans = min(ans, root.val - prev)

            prev = root.val

            dfs(root.right)

        dfs(root)
        
        return ans
            