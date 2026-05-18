class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        
        m = len(rides)

        dp = [0] * (n + 1)

        indexes = defaultdict(list)

        ans = 0
        
        for i in range(m):
            indexes[rides[i][1]].append(i)

        for i in range(n + 1): 
            dp[i] = ans
            for ind in indexes[i]:
                start, end, tip = rides[ind]    
                dp[i] = max(dp[i], end - start + tip + dp[start])
                ans = max(ans, dp[i])
        

        return ans