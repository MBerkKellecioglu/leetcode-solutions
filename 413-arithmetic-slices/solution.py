class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        
        n, ans = len(nums), 0

        dp = [0] * (n)

        for i in range(2, n):
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
                dp[i] = dp[i - 1] + 1
                ans += dp[i]
        
        return ans