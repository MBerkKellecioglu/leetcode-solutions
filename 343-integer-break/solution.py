class Solution:
    def integerBreak(self, n: int) -> int:
        
        if n <= 2:
            return 1
        
        dp = [0] * (n + 1)

        print(dp)

        dp[1] = 1
        dp[2] = 1
        dp[3] = 2

        for i in range(4, n + 1):
            for j in range(i // 2, i - 1):
                product = max(j, dp[j]) * max((i - j), dp[i - j])
                dp[i] = max(dp[i], product)

        return dp[n]

