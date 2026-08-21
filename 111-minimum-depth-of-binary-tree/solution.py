# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:

        if root is None:
            return 0

        q = deque()

        q.append(root)

        ans = 1

        while q:
            sz = len(q)

            while sz > 0:
                curr = q.popleft()

                if curr.left is None and curr.right is None:
                    return ans

                if curr.left:
                    q.append(curr.left)
                
                if curr.right:
                    q.append(curr.right)

                sz -= 1

            ans += 1
