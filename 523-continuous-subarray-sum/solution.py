class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        
        total = 0

        mods = {}

        mods[0] = -1

        for idx, num in enumerate(nums):
            total += num

            if total % k in mods and idx - mods[total % k] > 1:
                return True
            
            if total % k not in mods:
                mods[total % k] = idx
        
        return False