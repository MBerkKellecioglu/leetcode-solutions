class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        
        n,m = len(grid),len(grid[0])

        rows = [0] * n
        cols = [0] * m

        ans = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    rows[i] += 1
                    cols[j] += 1


        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    if rows[i] >= 2 or cols[j] >= 2:
                        ans += 1
        
        return ans