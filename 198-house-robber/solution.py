class Solution:
    def rob(self, nums: List[int]) -> int:
        
        n = len(nums)

        if n < 2:
            return nums[0]

        p2 = nums[0]
        p1 = max(nums[0], nums[1])

        for i in range(2, n):
            curr = max(nums[i] + p2, p1)
            p2 = p1
            p1 = curr

        return max(p2,p1)
