class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        
        for idx,num in enumerate(nums):
            total = 0
            while num > 0:
                total += num % 10
                num //= 10
            
            if total == idx:
                return idx
        
        return -1