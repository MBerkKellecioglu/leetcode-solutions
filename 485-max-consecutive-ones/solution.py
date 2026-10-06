class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        
        ans, seq = 0, 0

        for bit in nums:
            if bit:
                seq += 1
            else:
                seq = 0
            
            ans = max(ans,seq)
        
        return ans
