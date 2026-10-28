class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        
        m,n = len(grid), len(grid[0])

        dp = [[defaultdict(int) for _ in range(n)] for _ in range(m)]

        dp[0][0][grid[0][0]] = 1

        for i in range(m):
            for j in range(n):
                
                if i - 1 >= 0:
                    for num in dp[i - 1][j].keys():
                        dp[i][j][num ^ grid[i][j]] = 1
                
                if j - 1 >= 0:
                    for num in dp[i][j - 1].keys():
                        dp[i][j][num ^ grid[i][j]] = 1
        
        return min(dp[m - 1][n - 1].keys())
