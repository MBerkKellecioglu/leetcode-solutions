class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        
        ans = []

        n = len(nums)

        l, r = 1, n - 2

        ls, rs = [0] * n, [0] * n

        while l < n:
            ls[l] = ls[l - 1] + nums[l - 1]
            rs[r] = rs[r + 1] + nums[r + 1]

            r -= 1
            l += 1

        for i in range(n):
            ans.append(abs(ls[i] - rs[i]))

        return ans
