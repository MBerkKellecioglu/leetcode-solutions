from collections import deque

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        dp = [0] * (n + 1)
        prefix = [0] * (n + 1)

        dp[0] = 1
        prefix[0] = 1

        min_dq = deque()
        max_dq = deque()

        left = 0

        for right in range(n):
            while min_dq and nums[min_dq[-1]] >= nums[right]:
                min_dq.pop()
            min_dq.append(right)

            while max_dq and nums[max_dq[-1]] <= nums[right]:
                max_dq.pop()
            max_dq.append(right)

            while nums[max_dq[0]] - nums[min_dq[0]] > k:
                if min_dq[0] == left:
                    min_dq.popleft()
                if max_dq[0] == left:
                    max_dq.popleft()
                left += 1

            dp[right + 1] = (prefix[right] - (prefix[left - 1] if left > 0 else 0)) % MOD
            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD

        return dp[n]
