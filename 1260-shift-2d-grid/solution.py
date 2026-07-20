class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        
        m, n = len(grid), len(grid[0])

        for shift in range(k):
            prev = grid[0][0]
            for r in range(m):
                for c in range(n):
                    grid[r][c], prev = prev, grid[r][c]

            grid[0][0] = prev    
            

        return grid