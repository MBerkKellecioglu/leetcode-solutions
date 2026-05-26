class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        
        n = len(s)

        if s[-1] != '0':
            return False

        dp = [False] * n
        dp[0] = True

        valid = 0

        for i in range(1, n):

            if i - minJump > - 1 and dp[i - minJump]:
                valid += 1

            if i - maxJump - 1 >= 0 and dp[i - maxJump - 1]:
                valid -= 1
            
            dp[i] = True if (s[i] == "0" and valid > 0) else False

        return dp[-1]
            
