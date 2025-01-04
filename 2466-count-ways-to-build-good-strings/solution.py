class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        
        dp = [0] * (high + 1)
        ans = 0

        dp[0] = 1

        for i in range (1, high + 1):

            dp[i] += dp[i - zero]
            dp[i] += dp[i - one]

            if(i >= low and i <= high):
                ans += dp[i]
        

        ans %= (10**9) + 7
        return ans