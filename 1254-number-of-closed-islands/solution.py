class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:

        m,n = len(grid), len(grid[0])

        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        valid = (lambda y,x : 0 <= y < m and 0 <= x < n)

        ans = 0

        def bfs(y,x):

            q = deque()

            q.append((y,x))

            closed = True

            while q:
                cy,cx = q.popleft()

                grid[cy][cx] = -1

                if closed and (cy == m - 1 or cx == n - 1 or cy == 0 or cx == 0):
                    closed = False
                
                for dy,dx in directions:
                    ny,nx = cy + dy, cx + dx

                    if valid(ny,nx) and grid[ny][nx] == 0:
                        grid[ny][nx] = -1
                        q.append((ny,nx))
        
            return closed

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    ans += int(bfs(i,j))
     
        return ans