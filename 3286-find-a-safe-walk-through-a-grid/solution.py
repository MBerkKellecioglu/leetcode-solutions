class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        
        n, m = len(grid), len(grid[0])

        q = []

        dp = [[float("inf") for j in range(m)] for i in range(n)]

        dp[0][0] = grid[0][0]

        q.append((0,0))

        while q:
            i,j = q.pop(0)

            h = dp[i][j]

            if i + 1 < n and h + grid[i + 1][j] < dp[i + 1][j]:
                dp[i + 1][j] = h + grid[i + 1][j]
                q.append((i + 1,j))

            if i - 1 >= 0 and h + grid[i - 1][j] < dp[i - 1][j]:
                dp[i - 1][j] = h + grid[i - 1][j]
                q.append((i - 1,j))
            
            if j + 1 < m and h + grid[i][j + 1] < dp[i][j + 1]:
                dp[i][j + 1] = h + grid[i][j + 1]
                q.append((i,j + 1))
            
            if j - 1 >= 0 and h + grid[i][j - 1] < dp[i][j - 1]:
                dp[i][j - 1] = h + grid[i][j - 1]
                q.append((i, j - 1))

        #print(dp[n - 1][m - 1])

        return dp[n - 1][m - 1] < health