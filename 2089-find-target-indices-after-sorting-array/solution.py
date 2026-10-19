class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
    
        freq, before = 0, 0

        for num in nums:
            if num < target:
                before += 1
            elif target == num:
                freq += 1
        
        return [i for i in range(before, before + freq)]