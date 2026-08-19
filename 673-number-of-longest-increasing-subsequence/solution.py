class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        
        n = len(nums)

        dp = [[1,1] for _ in range(n)]

        dp[-1] = [1,1] # length, num

        max_len, ans = 1, 1

        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if nums[i] < nums[j]:
                    if dp[j][0] + 1 > dp[i][0]:
                        dp[i] = [dp[j][0] + 1, dp[j][1]]
                    elif dp[j][0] + 1 == dp[i][0]:
                        dp[i][1] += dp[j][1]
                
            if dp[i][0] > max_len:
                ans = dp[i][1]
                max_len = dp[i][0]
            elif dp[i][0] == max_len:
                ans += dp[i][1]

        return ans