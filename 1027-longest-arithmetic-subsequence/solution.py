class Solution:
    def longestArithSeqLength(self, nums: list[int]) -> int:
        
        n, ans = len(nums), 1

        dp = [{} for _ in range(n + 1)]

        for i in range(n - 2, -1, -1):
            checked = defaultdict(bool)

            for j in range(i + 1, n):
                diff = nums[j] - nums[i]

                if checked[diff]:
                    continue

                if diff in dp[j]:
                    dp[i][diff] = dp[j][diff] + 1
                else:
                    dp[i][diff] = 2
                
                checked[diff] = True
                
                ans = max(ans, dp[i][diff])

        return ans