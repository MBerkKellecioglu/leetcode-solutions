# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode | None) -> int:
        
        # find every left most and right most node for every level
        # while finding them rank every nodes idx between [1...2**n] -> n being curr height

        levels = defaultdict(lambda: [float("inf"),float("-inf")])

        ans = -1

        def dfs(node,rank,level):
            if not node:
                return

            levels[level][0] = min(levels[level][0],rank)
            levels[level][1] = max(levels[level][1],rank)

            dfs(node.left,rank * 2, level + 1)
            dfs(node.right,rank * 2 - 1, level + 1)

            return 
        
        dfs(root,1,0)

        for level,min_max in levels.items():
            mini,maxi = min_max

            ans = max(ans,maxi - mini + 1)

        return ans




