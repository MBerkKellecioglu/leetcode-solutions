class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        
        n = len(nums)

        curr_sub = 0

        for i in range(n):
            if i >= k:
                curr_sub -= nums[i - k]
            
            nums[i] -= curr_sub

            if nums[i] < 0:
                return False
            
            if nums[i] > 0 and i + k > n:
                return False

            curr_sub += nums[i]
        
        return True




