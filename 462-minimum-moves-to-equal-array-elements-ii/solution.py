class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        
        n, ans = len(nums), 0

        nums.sort()

        middle = nums[n // 2]

        for num in nums:
            ans += abs(middle - num)

        return ans