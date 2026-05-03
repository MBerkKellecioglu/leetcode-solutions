class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        
        n, ans = len(nums), 0
        
        dp = {}

        def createMatrix(n):
            return [[-1]*n for _ in range(n)]

        dp[nums[0] + nums[1]] = createMatrix(n)
        dp[nums[n - 1] + nums[n - 2]] = createMatrix(n)
        dp[nums[0] + nums[-1]] = createMatrix(n)

        def dfs(start, end, score):
            if end - start < 1:
               return 0

            if dp[score][start][end] != -1:
                return dp[score][start][end]

            op1 = nums[start] + nums[start + 1]
            op2 = nums[end] + nums[end - 1]
            op3 = nums[start] + nums[end]

            val1, val2, val3 = 0, 0, 0

            if op1 == score:
                val1 = dfs(start + 2, end, score) + 1
            if op2 == score:
                val2 = dfs(start, end - 2, score) + 1
            if op3 == score:
                val3 = dfs(start + 1, end - 1, score) + 1

            dp[score][start][end] = max(val1, val2, val3)

            return dp[score][start][end]
    
        ans = max(ans, dfs(0, n - 1, nums[0] + nums[1]))
        ans = max(ans, dfs(0, n - 1, nums[n - 1] + nums[n - 2]))
        ans = max(ans, dfs(0, n - 1, nums[0] + nums[-1]))

        
        return ans
