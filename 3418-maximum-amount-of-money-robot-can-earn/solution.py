class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:

        m, n = len(coins), len(coins[0])
        
        curr = [[float("-inf") for i in range(3)] for j in range(n)]

        curr[0][1] = max(0, coins[0][0])
        curr[0][2] = coins[0][0]

        for i in range(1, n):
            curr[i][0] = max(curr[i - 1][0] + coins[0][i], curr[i - 1][1])
            curr[i][1] = max(curr[i - 1][1] + coins[0][i], curr[i - 1][2])
            curr[i][2] = curr[i - 1][2] + coins[0][i]

        for i in range(1, m):
            nxt = [[float("-inf") for i in range(3)] for j in range(n)]
            for j in range(n):
                nxt[j][0] = max(curr[j][0] + coins[i][j], curr[j][1])
                nxt[j][1] = max(curr[j][1] + coins[i][j], curr[j][2])
                nxt[j][2] = curr[j][2] + coins[i][j]

                if j - 1 >= 0:
                    nxt[j][0] = max(nxt[j][0], nxt[j - 1][0] + coins[i][j], nxt[j - 1][1])
                    nxt[j][1] = max(nxt[j][1], nxt[j - 1][1] + coins[i][j], nxt[j - 1][2])
                    nxt[j][2] = max(nxt[j][2], nxt[j - 1][2] + coins[i][j])
            
            curr = nxt[:]

        return max(curr[n - 1])
