class Solution:
    def canIWin(self, maxI: int, desired: int) -> bool:

        # Using bits to represent numbers that has been picked is a brilliant idea
        # This is one of the cases where DFS + Memo is more efficent than Iterative DP

        if (maxI * (maxI + 1)) // 2 < desired:
            return False
    
        dp = {}

        """
        A bit tricky DFS logic. Basically this DFS ensures that both players play optimally.
        But if so how do we know our player is winning or losing since we do not know which DFS
        call belongs to which player. 

        Since we started from dfs(0,0) player 1 gets the ahead start and we traverse states
        according to his first pick we ensure that all state conditions belongs to player 1.

        However if we made a for loop iterating through choosable integers and start a dfs call
        from every one of them (means we start dfs call after player 1 chooses the first number)
        we would get state conditions belonging to player 2.

        If you did not get the logic you can just use a alternating flag (single bit) to see 
        which player is choosing which number. Flag starts with player 1 and every step of DFS 
        you flip that bit.
        """

        def dfs(state,total):

            if state in dp:
                return dp[state]
            
            for i in range(1, maxI + 1):
                mask = (1 << i)

                # nth bit represents nth number (e.g 1101 means 1 and 3 and 4 has been picked)
                if (state & mask) == 0:

                    if total + i >= desired or not dfs(state | mask, total + i):
                        dp[state] = True
                        return True

            dp[state] = False
            return False

        return dfs(0,0)