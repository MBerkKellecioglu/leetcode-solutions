class Solution:
    def minCut(self, s: str) -> int:
        
        n = len(s)

        palindrome = [[0 for _ in range(n)] for _ in range(n)]

        dp = [0] * n

        for i in range(n):
            palindrome[i][i] = 1

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j] and (i + 1 > j - 1 or palindrome[i + 1][j - 1]):
                    palindrome[i][j] = 1

        for i in range(n):
            dp[i] = 0 if palindrome[0][i] else i
            for j in range(1, i + 1):
                if palindrome[j][i]:
                    dp[i] = min(dp[i], dp[j - 1] + 1)

        return dp[n - 1]