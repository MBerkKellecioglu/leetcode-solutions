# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:

        ans = float("-inf")

        def dfs(node):
            nonlocal ans

            if not node:
                return [0, True, float("-inf"), float("inf")]

            ls, lBST, lmax, lmin = dfs(node.left)
            
            rs, rBST, rmax, rmin = dfs(node.right)

            total = ls + rs + node.val
            
            maxi = max(node.val, lmax, rmax)
            mini = min(node.val, lmin, rmin)

            isBST = True if lmax < node.val < rmin and lBST and rBST else False

            if isBST:
                ans = max(ans, total)

            return [total, isBST, maxi, mini]

        dfs(root)

        return ans if ans > 0 else 0