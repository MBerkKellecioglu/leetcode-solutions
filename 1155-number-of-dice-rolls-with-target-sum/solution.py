class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        
        dp = [[0] * (target + 1) for _ in range(n + 1)]

        MOD = 10**9 + 7

        for faceup in range(1,min(k + 1, target + 1)):
            dp[1][faceup] = 1

        for dice in range(2,n + 1):
            for t in range(1,target + 1):
                for faceup in range(1,k + 1):
                    if t - faceup >= 0:
                        dp[dice][t] = (dp[dice][t] + dp[dice - 1][t - faceup]) % MOD
    
        return dp[n][target]