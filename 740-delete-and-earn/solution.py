class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        
        freq = defaultdict(int)
        maxi, ans = max(nums) + 1, 0
        
        dp = [0] * maxi

        for num in nums:
            freq[num] += 1

        for i in range(1, maxi):
            dp[i] = max((i * freq[i]) + dp[i - 2], ans)

            ans = max(ans, dp[i])
        
        return ans