class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        
        n = len(fruits)

        dp = [[0] * n for _ in range(n)]

        dp[0][0] = fruits[0][0]
        dp[n - 1][0] = fruits[n - 1][0]
        dp[0][n - 1] = fruits[0][n - 1]

        # Child starting (0,0) can only move diagonally (n - 1 moves) 
        for i in range(1, n - 1):
            dp[i][i] += dp[i - 1][i - 1] + fruits[i][i] 
    
        #We are scanning bottom triangle bounded by diagonals, top to bottom exclusive
        #bottom to top inclusive for child starting from (n - 1, 0) (n - 1 moves)
        for c in range(n):
            for r in range(n - 1, max(n - c - 2, c), -1):
                fruit = fruits[r][c]

                if c - 1 >= 0 and r >= max(n - c, c):
                    dp[r][c] = dp[r][c - 1] + fruit

                if c - 1 >= 0 and r - 1 >= max(n - c, c):
                    dp[r][c] = max(dp[r][c], dp[r - 1][c - 1] + fruit)
                    
                if r + 1 < n:
                    dp[r][c] = max(dp[r][c], dp[r + 1][c - 1] + fruit)

        # Now same thing as above with right most triangle bounded by both diagonals
        for r in range(n):
            for c in range(n - 1, max(n - r - 2, r), -1):
                fruit = fruits[r][c]

                if r - 1 >= 0 and c >= max(n - r, r):
                    dp[r][c] = dp[r - 1][c] + fruit
                
                if r - 1 >= 0 and c - 1 >= max(n - r, r):
                    dp[r][c] = max(dp[r][c], dp[r - 1][c - 1] + fruit)

                if c + 1 < n:
                    dp[r][c] = max(dp[r][c], dp[r - 1][c + 1] + fruit)

        # update last cell
        dp[n - 1][n - 1] = dp[n - 2][n - 2] + dp[n - 1][n - 2] + dp[n - 2][n - 1] + fruits[n - 1][n - 1]
                
        return dp[n - 1][n - 1]