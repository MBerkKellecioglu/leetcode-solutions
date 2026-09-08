class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        
        n = len(nums)

        dp = [defaultdict(int) for _ in range(n)]

        ans = 0

        for i in range(n):
            for j in range(i - 1, -1, -1):
                diff = nums[i] - nums[j]

                count = dp[j][diff]

                ans += count

                dp[i][diff] += count + 1
        
        return ans
    
