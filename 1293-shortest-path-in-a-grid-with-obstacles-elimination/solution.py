class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:

        m,n,steps = len(grid),len(grid[0]),0
        
        q = deque()

        q.append((0,0,k))

        directions = [[1,0],[0,1],[-1,0],[0,-1]]

        valid = lambda y, x : 0 <= y < m and 0 <= x < n

        dp = [[-1] * n for _ in range(m)]

        dp[0][0] = k
        
        while q:
            sz = len(q)

            while sz > 0:
                y,x,obs = q.popleft()

                if (y,x) == (m - 1, n - 1):
                    return steps
                
                for dy,dx in directions:
                    ny,nx = y + dy, x + dx

                    if valid(ny,nx):
                        next_obs = obs

                        if grid[ny][nx] == 1:
                            next_obs -= 1

                        if dp[ny][nx] < next_obs:
                            dp[ny][nx] = next_obs 

                            q.append((ny,nx, next_obs))
                    
                sz -= 1
            
            steps += 1

        return -1   
