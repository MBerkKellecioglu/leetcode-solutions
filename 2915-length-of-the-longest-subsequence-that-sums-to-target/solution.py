class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        
        dp = [[-1 for i in range(target + 1)] for j in range(len(nums))]

        ans = -1

        dp[0][0] = 0
        
        if nums[0] <= target:
            dp[0][nums[0]] = 1

        for i in range(1, len(nums)):
            for j in range(target + 1):
                dp[i][j] = dp[i - 1][j]

                if j - nums[i] >= 0 and dp[i - 1][j - nums[i]] != -1:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i]] + 1)

        return dp[len(nums) - 1][target]