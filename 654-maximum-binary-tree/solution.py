# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        
        l,r,n = 0, len(nums) - 1, len(nums)

        def construct(l,r):
            if l > r:
                return None
            
            if r - l == 0:
                return TreeNode(nums[l])
            
            sliced = nums[l:r + 1]
            val = max(sliced)
            idx = nums.index(val)
            node = TreeNode(val)

            node.left = construct(l, idx - 1)
            node.right = construct(idx + 1, r)

            return node

        return construct(l, r)
            
            
