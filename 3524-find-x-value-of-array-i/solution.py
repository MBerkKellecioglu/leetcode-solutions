class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        
        n = len(nums)

        dp = [[0] * k for _ in range(n)]

        ans = [0] * k

        dp[0][nums[0] % k] += 1

        ans[nums[0] % k] += 1

        for i in range(1,n):
            for remainder in range(k):
                if dp[i - 1][remainder] > 0:
                    new_remainder = (remainder * nums[i]) % k

                    dp[i][new_remainder] += dp[i - 1][remainder]

                    ans[new_remainder] += dp[i - 1][remainder]

            dp[i][nums[i] % k] += 1

            ans[nums[i] % k] += 1

        return ans
