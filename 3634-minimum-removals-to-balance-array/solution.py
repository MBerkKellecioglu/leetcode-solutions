class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:

        l, r, n = 0, 1, len(nums)

        window = 0

        if n == 1:
            return window

        nums.sort()

        while r < n:
            if nums[l] * k >= nums[r]:
                window = max(window, r - l + 1)
                r += 1
            else:
                l += 1

        return n - window  