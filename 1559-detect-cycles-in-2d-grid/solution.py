class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:

        n, m = len(grid), len(grid[0])

        checked = [[0 for i in range(m)] for j in range(n)]

        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        def dfs(row, col, prev_row, prev_col):

            checked[row][col] = True

            valid = False 

            for dr, dc in directions:
                
                if (n > row + dr > -1) and (m > col + dc > -1): # boundry check
                    if grid[row + dr][col + dc] == grid[row][col]: # same value check
                        if (row + dr, col + dc) != (prev_row, prev_col): # parent check
                            if checked[row + dr][col + dc]:
                                return True
                            else:
                                valid |= dfs(row + dr, col + dc, row, col)
            return valid 

        for i in range(n):
            for j in range(m):
                if not checked[i][j] and dfs(i, j, -1,-1):
                    return True
        
        return False
