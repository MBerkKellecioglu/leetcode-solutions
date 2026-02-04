class Solution:
    def minimumCost(self, nums: List[int]) -> int:

        n = len(nums)
        
        l1, l2, l3 = nums[0], min(nums[1], nums[2]), max(nums[1], nums[2])

        for i in range(3,n):
            num = nums[i]

            if l2 > num:
                l3 = l2
                l2 = num
            elif l3 > num:
                l3 = num

        
        return l1 + l2 + l3 
