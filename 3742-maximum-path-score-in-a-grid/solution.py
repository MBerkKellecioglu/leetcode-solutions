class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:

        n, m = len(grid), len(grid[0])

        dp = [[[-1 for i in range(k + 1)] for j in range(m)] for i in range(n)]
        
        if grid[0][0] >= 1:
            dp[0][0][1] = grid[0][0]
        else:
            dp[0][0][0] = 0
 
        for i in range(n):
            for j in range(m):
                score = grid[i][j]
                limit = (score > 0)
                for t in range(k + 1 - limit):
                    if j - 1 > -1 and dp[i][j - 1][t] != -1:
                        dp[i][j][t + limit] = dp[i][j - 1][t] + score
                    if i - 1 > -1 and dp[i - 1][j][t] != -1:
                        dp[i][j][t + limit] = max(dp[i][j][t + limit], dp[i - 1][j][t] + score)

        return max(dp[n - 1][m - 1])