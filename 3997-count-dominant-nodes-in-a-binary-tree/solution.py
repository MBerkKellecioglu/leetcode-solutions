# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countDominantNodes(self, root: TreeNode | None) -> int:
        
        ans = 0

        def dfs(node):
            nonlocal ans

            if not node:
                return -1
            
            maxi = max(dfs(node.right),dfs(node.left))

            if maxi <= node.val:
                ans += 1

            return max(maxi,node.val)

        dfs(root)

        return ans