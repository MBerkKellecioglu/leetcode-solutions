class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:

        dp = [1] * (n + 1)

        dp[0] = 1

        def perm(i):
            if i <= 1:
                return 9

            ans = 9

            for j in range(1,i):
                ans *= (9 - (j - 1))
            
            return ans

        for i in range(1, n + 1):
            dp[i] = perm(i) + dp[i - 1]

        return dp[n]
