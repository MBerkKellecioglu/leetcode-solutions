# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Index:

    def __init__(self, i = 0):
        self.i = i


class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:

        split = re.findall("-+[0-9]+", traversal)

        nodes = []

        ind = Index(0)

        for s in split:
            i = 0
            level = 0

            while s[i] == '-':
                i += 1
                level += 1           

            nodes.append([level, int(s[i:])])

        i = 0

        while i < len(traversal) and traversal[i] != '-':
            i += 1
        
        root = TreeNode(int(traversal[:i]))

        def dfs(root, level, ind):

            if(ind.i >= len(nodes)):
                return root
            
            curr = nodes[ind.i]

            if level + 1 == curr[0]:
                if root.left == None: 
                    root.left = TreeNode(curr[1])
                    ind.i += 1
                    dfs(root.left, level + 1, ind)
            
            if(ind.i >= len(nodes)):
                return root

            curr = nodes[ind.i]

            if level + 1 == curr[0]:
                if root.right == None:
                    root.right = TreeNode(curr[1])
                    ind.i += 1
                    dfs(root.right, level + 1, ind)


            return root
        
        
        dfs(root, 0, ind)

        return root