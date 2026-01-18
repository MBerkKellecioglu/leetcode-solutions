class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        
        ans, n = nums[0], len(nums)
        
        prefix, first = nums[0], nums[0]
        
        for i in range(1, n):
            prefix += nums[i]

            average = ceil(prefix / (i + 1))

            first = average

            ans = max(ans, average)

        return ans

