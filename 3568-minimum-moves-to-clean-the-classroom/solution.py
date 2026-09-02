class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:

        m, n = len(classroom), len(classroom[0])
        
        l_idx = {} # litter indexes
        idx = 0

        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        valid = lambda y, x: 0 <= y < m and 0 <= x < n
 
        q = deque()

        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'L':
                    l_idx[(i,j)] = idx
                    idx += 1
                
                if classroom[i][j] == 'S':
                    q.append((i,j,0,energy,0))

        l = 2 ** (idx)

        dp = [[[float("-inf")] * l for _ in range(n)] for _ in range(m)]

        while q:
            y,x,mask,e,steps = q.popleft()
            
            if mask == l - 1:
                return steps

            if e <= 0 and classroom[y][x] != 'R':
                continue

            for dy,dx in directions:
                ny,nx = y + dy, x + dx

                if valid(ny,nx) and classroom[ny][nx] != 'X':
                    new_mask = mask
                    new_e = e - 1

                    if classroom[ny][nx] == 'L':
                        idx = l_idx[(ny,nx)]

                        new_mask |= (1 << idx)

                    elif classroom[ny][nx] == 'R':
                        new_e = energy

                    if dp[ny][nx][new_mask] < new_e:
                        dp[ny][nx][new_mask] = new_e

                        q.append((ny,nx,new_mask,new_e,steps + 1))
            
        return -1