class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        
        n = len(nums)

        dp = [0 for i in range(n)]

        for j in range(n):
            for i in range(j - 1, -1, -1):
                if abs(nums[i] - nums[j]) <= target:
                    if dp[i] != 0 or i == 0:
                        dp[j] = max(dp[j], dp[i] + 1)
        
        return dp[-1] if dp[-1] != 0 else -1
            