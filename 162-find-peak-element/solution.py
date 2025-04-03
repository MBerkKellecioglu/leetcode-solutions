class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        l = 0
        r = len(nums)

        while l <= r:
            mid = (r + l) // 2

            flag1 = False
            flag2 = False

            if mid - 1 > -1:
                if nums[mid] < nums[mid - 1]:
                    r = mid - 1
                    continue
                else:
                    flag1 = True
            else:
                flag1 = True

            if mid + 1 < len(nums):
                if nums[mid] < nums[mid + 1]:
                    l = mid + 1
                else:
                    flag2 = True
            else:
                flag2 = True
            
            if flag1 and flag2:
                return mid
          
        return 0