dp = [[float("inf")] * 201 for _ in range(201)] 

dp[1][1] = 0
        
def dfs(l, r):
    if dp[l][r] != float("inf"):
        return dp[l][r]

    if l >= r:
        return 0

    for i in range(l, r):
        segment = i + max(dfs(i + 1, r), dfs(l, i - 1))

        dp[l][r] = min(dp[l][r], segment)

    return dp[l][r]

dfs(1, 200)

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        
        return dp[1][n]