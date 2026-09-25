class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        
        n, ans = len(nums), 2

        dp = [defaultdict(int) for _ in range(n)]

        for i in range(1,n):
            for j in range(i - 1, -1, -1):
                remainder = (nums[i] + nums[j]) % k
                
                if dp[j][remainder] == 0:
                    dp[i][remainder] = max(dp[i][remainder],2)
                else:
                    dp[i][remainder] = max(dp[i][remainder],dp[j][remainder] + 1)
        
                ans = max(ans, dp[i][remainder])
                
        return ans