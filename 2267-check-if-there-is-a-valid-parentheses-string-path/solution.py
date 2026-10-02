class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        
        m,n = len(grid), len(grid[0])

        dp = [[0] * n for _ in range(m)]

        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False

        # binary 2 is 10 and that means we have 1 open bracket at the start
        dp[0][0] = 2 

        # nth bit means we have n open bracket path and first bit (0th) means we have valid path

        for i in range(m):
            for j in range(n):
                left_mask,top_mask = 0,0

                if i == 0 and j == 0:
                    continue

                if i - 1 >= 0:
                    top_mask = dp[i - 1][j]

                if j - 1 >= 0:
                    left_mask = dp[i][j - 1]
                
                curr_mask = top_mask | left_mask

                if grid[i][j] == '(':
                    curr_mask = curr_mask << 1
                else:
                    curr_mask = curr_mask >> 1
                
                dp[i][j] = curr_mask
        
        # if 0th bit is 1 that means we have valid path and also means number that currently dp cell holds is odd 
        return dp[m - 1][n - 1] % 2 == 1                


                    


