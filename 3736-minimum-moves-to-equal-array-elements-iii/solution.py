class Solution:
    def minMoves(self, nums: List[int]) -> int:
        
        maxi,ans = max(nums),0
        
        for num in nums:
            ans += (maxi - num)
        
        return ans