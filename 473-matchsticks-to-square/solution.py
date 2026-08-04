class Solution:
    def makesquare(self, ms: List[int]) -> bool:
        
        total,n = sum(ms),len(ms)

        if total % 4:
            return False
        
        edges = [total // 4] * 4

        if max(ms) > edges[0]:
            return False

        dp = {}

        def dfs(mask, idx):
            if mask == (1 << n) - 1 and sum(edges) == 0:
                return True

            if mask in dp:
                return dp[mask]

            for i in range(n):
                if (mask & (1 << i)) == 0:
                
                    if edges[idx] - ms[i] >= 0:
                        edges[idx] -= ms[i]

                        if dfs(mask | (1 << i), idx + (edges[idx] == 0)):
                            dp[mask] = True
                            return True
                        
                        edges[idx] += ms[i]
            
            dp[mask] = False
            return dp[mask]

        return dfs(0,0)