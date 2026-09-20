class Solution:
    def numberOfSets(self, n: int, k: int) -> int:

        MOD = 10**9 + 7
        
        # dp[i][j] -> All line segments with total j lines ending ONLY ON POINT i
        dp = [[0] * (k + 1) for _ in range(n + 1)] 

        # prefix[i][j] -> Total ways of j lines at point i
        prefix = [[0] * (k + 1) for _ in range(n + 1)]

        for point in range(n):
            prefix[point][0] = 1

        for line in range(1, k + 1):
            for point in range(1, n):
                dp[point][line] = (dp[point - 1][line] + prefix[point - 1][line - 1]) % MOD

                prefix[point][line] = (prefix[point - 1][line] + dp[point][line]) % MOD

        return prefix[n - 1][k]