class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        
        total, prefix, ans = sum(nums), 0, len(nums)
        remainder = total % p

        seen = {0 : -1}

        if remainder == 0:
            return 0
        
        for i, num in enumerate(nums):
            prefix = (prefix + num) % p
            target = (prefix - remainder) % p

            if target in seen:
                ans = min(ans, i - seen[target])

            seen[prefix] = i

        return ans if ans < len(nums) else -1


            