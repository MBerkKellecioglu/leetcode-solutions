class Solution:
    def sortPermutation(self, nums: List[int]) -> int:

        n = len(nums)

        ans = -1

        for i in range(n):
            if i != nums[i]:
                ans &= nums[i]
             

        return ans if ans != -1 else 0