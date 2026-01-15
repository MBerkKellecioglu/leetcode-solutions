class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])

        dp = [[0 for i in range(m)] for j in range(n)]

        dp[n - 1][m - 1] = 1 if dungeon[n - 1][m - 1] > 0 else abs(dungeon[n - 1][m - 1]) + 1

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if i == n - 1 and j == m - 1:
                    continue
                
                need1, need2 = float("inf"), float("inf")

                if i + 1 < n:
                    need1 = max(1, dp[i + 1][j] - dungeon[i][j])
                
                if j + 1 < m:
                    need2 = max(1, dp[i][j + 1] - dungeon[i][j])
                
                dp[i][j] = min(need1, need2)

        return dp[0][0]
