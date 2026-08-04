class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        m,n = len(mat),len(mat[0])
    
        dists = [[0] * n for _ in range(m)]
    
        dir = [[1,0],[-1,0],[0,1],[0,-1]]

        q = deque()
    
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    for y,x in dir:
                        if 0 <= i+y < m and 0 <= j+x < n and mat[i+y][j+x] == 0:
                            dists[i][j] = 1
                            q.append((i,j))
                            break
        
        while q:
            sz = len(q)

            while sz > 0:
                i,j = q.popleft()

                for y,x in dir:
                    if 0 <= i+y < m and 0 <= j+x < n and mat[i + y][j + x] == 1 and dists[i + y][j + x] == 0:
                        dists[i + y][j + x] = dists[i][j] + 1
                        q.append((i + y, j + x))

                sz -= 1
    
        return dists
                
        
        
                        
                
        