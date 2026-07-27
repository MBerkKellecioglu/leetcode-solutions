class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        
        nums.sort()

        perimeter = nums[0] + nums[1] + nums[2]

        ans = perimeter if nums[0] + nums[1] > nums[2] else -1

        for i in range(3,len(nums)):
            if perimeter > nums[i]:
                ans = max(ans, perimeter + nums[i])
            
            perimeter += nums[i]

        
        return ans
