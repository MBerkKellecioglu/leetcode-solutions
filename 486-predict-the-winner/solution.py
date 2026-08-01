class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        
        n, total = len(nums), sum(nums)

        dp = [[-1] * n for _ in range(n)]

        def dfs(l, r):
            if l > r:
                return 0

            if dp[l][r] != -1:
                return dp[l][r]

            op1 = nums[l] + min(dfs(l + 2, r), dfs(l + 1, r - 1))      
            op2 = nums[r] + min(dfs(l + 1, r - 1), dfs(l, r - 2))
            
            dp[l][r] = max(op1, op2)  

            return dp[l][r]
    
        return dfs(0, n - 1) >= (total / 2)

