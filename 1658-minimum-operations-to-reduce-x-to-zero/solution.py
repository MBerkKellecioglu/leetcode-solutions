class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        
        l,r,n = 0,0,len(nums)

        max_len, total = -1, sum(nums)

        curr_sum, target = 0, total - x

        if total < target:
            return -1

        if total == target:
            return n

        while r < n:
            curr_sum += nums[r]

            while curr_sum > target and l <= r:
                curr_sum -= nums[l]
                l += 1
            
            if curr_sum == target:
                max_len = max(max_len, r - l + 1)

            r += 1

        if max_len == -1:
            return max_len

        return n - max_len


