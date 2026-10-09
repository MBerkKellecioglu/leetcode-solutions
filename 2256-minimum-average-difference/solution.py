class Solution:
    def minimumAverageDifference(self, nums: list[int]) -> int:
        
        n = len(nums)

        prefix = [0] * n
        suffix = [0] * n

        prefix[0] = nums[0]

        l,r = 1, n - 2

        ans, mini = 0, float("inf")

        while l < n:
            prefix[l] = prefix[l - 1] + nums[l]
            suffix[r] = suffix[r + 1] + nums[r + 1]

            l += 1
            r -= 1
        
        for i in range(n):
            first = prefix[i] // (i + 1)
            last = suffix[i] // max(1,n - i - 1)

            if mini > abs(first - last):
                ans = i
                mini = abs(first - last)
        
        return ans


