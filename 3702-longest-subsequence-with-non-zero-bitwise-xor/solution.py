class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        
        xor, n = nums[0], len(nums)

        zeros = (nums[0] == 0)

        for i in range(1, n):
            xor ^= nums[i]
            
            if nums[i] == 0:
                zeros += 1
        
        if xor != 0:
            return n
        else:
            if zeros == n:
                return 0
            else:
                return n - 1

        return -2