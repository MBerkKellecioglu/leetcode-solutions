# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        
        def dfs(node):
            if not node:
                return ""

            s = str(node.val)

            l = dfs(node.left)
            r = dfs(node.right)
            
            if l != "" and r != "":
                s += "(" + l + ")" + "(" + r + ")"
            elif l != "" and r == "":
                s += "(" + l + ")" 
            elif l == "" and r != "":
                s += "()" + "(" + r + ")" 
            
            return s

        return dfs(root)