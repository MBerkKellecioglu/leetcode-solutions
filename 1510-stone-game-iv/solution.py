class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        
        dp = [-1] * (n + 1)
        
        def dfs(pile):
            if pile <= 0:
                return False

            if dp[pile] != -1:
                return dp[pile]
            
            stone = 1

            while stone * stone <= pile:
                if not dfs(pile - stone * stone):
                    dp[pile] = True
                    return True

                stone += 1
            
            dp[pile] = False
            return False

        dfs(n)
        return dp[n]
