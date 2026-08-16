# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        
        freq = defaultdict(int)

        max_freq = float("-inf")

        def dfs(node):
            nonlocal max_freq

            if not node:
                return 0
            
            total = 0

            total = dfs(node.left) + dfs(node.right) + node.val

            freq[total] += 1

            max_freq = max(max_freq, freq[total])

            return total

        dfs(root)

        ans = []

        for key,val in freq.items():
            if val == max_freq:
                ans.append(key)

        return ans

