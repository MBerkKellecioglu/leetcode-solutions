class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:

        n, ans = len(nums),0

        nums.sort(key=abs)

        l,r = 0, n - 1

        while l < r:
            ans += (nums[r]**2) - (nums[l]**2)

            r -= 1
            l += 1

        if l == r:
            ans += (nums[r]**2)

        return ans 