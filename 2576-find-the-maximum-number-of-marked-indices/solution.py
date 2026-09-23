class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        
        nums.sort()

        n, ans = len(nums),0

        l, r = 0, n // 2

        while l < n // 2 and r < n:
            if nums[l] * 2 <= nums[r]:
                ans += 2
                l += 1
            
            r += 1
        
        return ans
            