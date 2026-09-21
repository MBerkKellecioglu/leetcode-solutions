class Solution:
    def shortestBridge(self, grid: list[list[int]]) -> int:

        m, n, group = len(grid), len(grid[0]),1
        
        # 1 means first island, 2 means second island
        islands = [[0] * n for _ in range(m)]

        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        inbounds = lambda y,x : (0 <= y < m and 0 <= x < n)

        q = deque()

        # find islands
        def dfs(y,x):
            nonlocal group

            if islands[y][x] == 1:
                # add first island parts to queue
                q.append((y,x,0))

            for dy,dx in directions:
                ny,nx = y + dy, x + dx

                if inbounds(ny,nx) and grid[ny][nx] and not islands[ny][nx]:
                    # group islands
                    islands[ny][nx] = group
                    dfs(ny,nx)

        for y in range(m):
            for x in range(n):
                if grid[y][x] and not islands[y][x]:
                    islands[y][x] = group
                    dfs(y,x)
                    # increase group because we found our first island
                    group += 1
        
        while q:
            y,x, dist = q.popleft()

            if islands[y][x] == 2:
                # reached second island
                return dist

            for dy,dx in directions:
                ny,nx,nd = y + dy, x + dx,dist

                # dont need to traverse first island anymore
                if inbounds(ny,nx) and islands[ny][nx] != 1 and grid[ny][nx] != 3:
                    if not grid[ny][nx]:
                        # 3 means we checked this zero (bridge cell) before
                        grid[ny][nx] = 3
                        nd += 1

                    q.append((ny,nx,nd))
                    
        return -1