class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        n, m = len(s1), len(s2)

        dp = [[0 for j in range(m + 1)] for i in range(n + 1)]

        for i in range(n - 1, -1, -1):
            dp[i][m] = dp[i + 1][m] + ord(s1[i: i + 1]) 

        for j in range(m - 1, -1, -1):
            dp[n][j] = dp[n][j + 1] + ord(s2[j : j + 1])

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                n1, n2 = ord(s1[i]), ord(s2[j])
                
                if s1[i] == s2[j]:
                    dp[i][j] = min(
                        dp[i + 1][j] + n1,
                        dp[i][j + 1] + n2,
                        dp[i + 1][j + 1]
                    )  
                else:
                    dp[i][j] = min(
                        dp[i + 1][j] + n1,
                        dp[i][j + 1] + n2,
                    )

        return dp[0][0]