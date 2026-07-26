# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        
        q = deque()

        q.append(root)

        while q:
            sz = len(q)
            level = []

            while sz > 0:
                curr = q.popleft()
                sz -= 1

                if not curr:
                    continue

                level.append(curr.left.val) if curr.left else level.append(float("inf"))
                level.append(curr.right.val) if curr.right else level.append(float("inf"))

                q.append(curr.left)
                q.append(curr.right)

            l, r = 0, len(level) - 1

            while l < r:
                if level[l] != level[r]:
                    return False
                l += 1
                r -= 1
                
        return True