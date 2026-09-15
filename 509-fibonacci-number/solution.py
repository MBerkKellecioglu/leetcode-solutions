dp = [0] * 31

dp[1] = 1

for i in range(2,31):
    dp[i] = dp[i - 1] + dp[i - 2]

class Solution:
    def fib(self, n: int) -> int:
        
        return dp[n]
        