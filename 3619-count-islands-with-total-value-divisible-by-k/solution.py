class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:

        m,n = len(grid),len(grid[0])
        
        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        valid = (lambda y,x : 0 <= y < m and 0 <= x < n)

        ans = 0

        def dfs(y,x):
            nonlocal total

            for dy,dx in directions:
                ny,nx = y + dy, x + dx

                if valid(ny,nx) and grid[ny][nx] > 0:
                    total += grid[ny][nx]
                    grid[ny][nx] = 0

                    dfs(ny,nx)
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    total = grid[i][j]
                    grid[i][j] = 0

                    dfs(i,j)

                    if not (total % k):
                        ans += 1
        
        return ans