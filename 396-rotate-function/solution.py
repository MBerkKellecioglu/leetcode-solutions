class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        
        first, last, mid, add, n = 0, len(nums) - 1, 0, 0, len(nums)

        for i in range(1, n):
            add += i * nums[i]
            mid += nums[i]
        
        mid -= nums[last]
        ans = add
        prev = add

        for i in range(1, n):
            prev = prev + mid - ((n - 1) * nums[last]) + nums[first]
            last -= 1
            mid -= nums[last]
            mid += nums[first] 

            first -= 1
            first %= n
            ans = max(ans, prev)

        return ans