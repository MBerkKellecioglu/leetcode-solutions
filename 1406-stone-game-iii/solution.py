class Solution:
    def stoneGameIII(self, nums: List[int]) -> str:
        
        n, total = len(nums), sum(nums)

        dp = [float("inf")] * n

        def dfs(l):
            if l >= len(nums):
                return 0

            if dp[l] != float("inf"):
                return dp[l]

            op1,op2,op3 = float("-inf"),float("-inf"),float("-inf")

            op1 = nums[l] + min(dfs(l + 2), dfs(l + 3), dfs(l + 4))
            
            if l + 1 < n:
                op2 = nums[l] + nums[l + 1] + min(dfs(l + 3), dfs(l + 4), dfs(l + 5))
            
            if l + 2 < n:
                op3 = nums[l] + nums[l + 1] + nums[l + 2] + min(dfs(l + 4), dfs(l + 5), dfs(l + 6))
            
            dp[l] = max(op1,op2,op3)

            return dp[l]

        dfs(0)

        if dp[0] > (total / 2):
            return "Alice"
        elif dp[0] < (total / 2):
            return "Bob"
        else:
            return "Tie"
