class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        
        maxi,mini,n = 0,0,len(nums)

        for i in range(len(nums)):
            if nums[maxi] < nums[i]:
                maxi = i

            if nums[mini] > nums[i]:
                mini = i

        maxi,mini = max(maxi,mini), min(maxi,mini)

        return min(mini + 1 + n - maxi, maxi + 1, n - mini)
            