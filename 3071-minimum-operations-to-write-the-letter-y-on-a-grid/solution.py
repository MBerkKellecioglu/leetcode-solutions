class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        
        n, ans = len(grid), float("inf")

        y = [0,0,0] # 0, 1, 2
        
        not_y = [0,0,0] 

        for r in range(n):
            for c in range(n):
                not_y[grid[r][c]] += 1
        
        for r in range( (n // 2)):
            y[grid[r][r]] += 1
            y[grid[r][n - r - 1]] += 1
            y[grid[n - r - 1][n // 2]] += 1
        
        y[grid[n // 2][n // 2]] += 1

        not_y[0] -= y[0]
        not_y[1] -= y[1]
        not_y[2] -= y[2]

        # not the most readable but y conversion to 0, 1,2 cross check with not_y conversion
        # ex -> y[1] + y[2] + not_y[0] + not_y[2] means y ->> zero + not_y ->> 1  
        ans = min(ans, y[1] + y[2] + not_y[0] + not_y[2], y[1] + y[2] + not_y[0] + not_y[1])
        ans = min(ans, y[0] + y[2] + not_y[1] + not_y[2], y[0] + y[2] + not_y[0] + not_y[1])
        ans = min(ans, y[0] + y[1] + not_y[1] + not_y[2], y[0] + y[1] + not_y[0] + not_y[2])   

        return ans