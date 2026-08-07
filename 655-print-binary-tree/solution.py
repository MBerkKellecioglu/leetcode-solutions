# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        
        m,n = 0, 0

        q = deque()

        q.append(root)

        while q:
            sz = len(q)

            while sz > 0:
                curr = q.popleft()

                if curr.left:
                    q.append(curr.left)
                    
                if curr.right:
                    q.append(curr.right)
                    
                sz -= 1
            
            m += 1
        
        n = 2**m - 1
        height = m - 1

        ans = [[""] * n for _ in range(m)]

        def dfs(node,r,c):
            nonlocal height
            if not node:
                return

            ans[r][c] = str(node.val)

            dfs(node.left, r + 1, c - 2**(height - r - 1))
            dfs(node.right, r + 1, c + 2**(height - r - 1))

        dfs(root,0,(n - 1) // 2)
        return ans
