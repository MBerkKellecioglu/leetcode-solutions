class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        
        n = len(grid)

        dist = [[float("inf")] * n for _ in range(n)]

        directions = [[0,1],[0,-1],[1,0],[-1,0]]

        q = deque()

        def findDist():
            nonlocal n

            while q:
                cy, cx = q.popleft()

                for dy,dx in directions:
                    ny, nx = cy + dy, cx + dx

                    if 0 <= ny < n and 0 <= nx < n:
                        if dist[cy][cx] + 1 < dist[ny][nx]:
                            dist[ny][nx] = dist[cy][cx] + 1
                            q.append((ny,nx))

        def bfs(target):
            nonlocal n

            deq = deque()

            checked = [[False] * n for _ in range(n)]

            if dist[0][0] < target:
                return False

            deq.append((0,0))

            while deq:
                cy, cx = deq.popleft()

                if cx == n - 1 and cy == n - 1:
                    return True

                for dy,dx in directions:
                    ny, nx = cy + dy, cx + dx

                    if 0 <= ny < n and 0 <= nx < n and not checked[ny][nx] and dist[ny][nx] >= target:
                        deq.append((ny,nx))
                        checked[ny][nx] = True
            
            return False


        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i,j))
        
        findDist()

        low, high, ans = 0, max(max(dist)), 0

        while low <= high:
            target = (high + low ) // 2

            if bfs(target):
                ans = target
                low = target + 1
            else:
                high = target - 1


        return ans


