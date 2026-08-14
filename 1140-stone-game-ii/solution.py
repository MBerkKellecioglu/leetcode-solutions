class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        
        n = len(piles)

        dp = [[float("-inf")] * n for _ in range(n)]

        suffix = [0] * n

        suffix[-1] = piles[-1]

        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        def dfs(idx, M):
            nonlocal n

            if 2*M >= (n - idx):
                return suffix[idx]

            if dp[idx][M] != float("-inf"):
                return dp[idx][M]

            max_gain = float("-inf")

            for X in range(1,2*M + 1):
                
                gain = suffix[idx] - dfs(idx + X, max(X,M))
                
                max_gain = max(max_gain, gain)

            dp[idx][M] = max_gain

            return max_gain

        return dfs(0,1)

