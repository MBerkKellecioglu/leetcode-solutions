class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        
        n = len(nums)

        dp = [[None] * (k + 1) for _ in range(n)]

        prefix = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + nums[i - 1]

        def dfs(idx,k):
            nonlocal n
            if idx >= n:
                return float("inf")
            
            if k == 1:
                return prefix[n] - prefix[idx]

            if dp[idx][k] != None:
                return dp[idx][k]

            ans = float("inf")
            
            for new_idx in range(idx,n):
                split_sum = prefix[new_idx + 1] - prefix[idx]

                curr_max = split_sum

                curr_max = max(curr_max, dfs(new_idx + 1,k - 1))

                ans = min(ans, curr_max)

            dp[idx][k] = ans

            return dp[idx][k]

        return dfs(0,k)