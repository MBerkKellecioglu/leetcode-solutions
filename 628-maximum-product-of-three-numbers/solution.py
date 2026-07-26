class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        
        mx1, mx2, mx3 = float("-inf"),float("-inf"),float("-inf")

        mn1, mn2 = float("inf"), float("inf")

        for i in range(len(nums)):
            if mx1 < nums[i]:
                mx3 = mx2
                mx2 = mx1
                mx1 = nums[i]
            elif mx2 < nums[i]:
                mx3 = mx2
                mx2 = nums[i]
            elif mx3 < nums[i]:
                mx3 = nums[i]
            
            if mn1 > nums[i]:
                mn2 = mn1
                mn1 = nums[i]
            elif mn2 > nums[i]:
                mn2 = nums[i]

        
        return max(mx1*mx2*mx3, mx1*mn1*mn2)
                
                