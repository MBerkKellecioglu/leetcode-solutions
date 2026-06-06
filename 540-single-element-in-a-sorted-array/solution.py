class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:

        n = len(nums)

        l, r = 0, n - 1

        while l <= r:
            mid = (l + r) // 2

            if (mid == 0 or nums[mid] > nums[mid - 1]) and (mid == n -1 or nums[mid] < nums[mid + 1]):
                return nums[mid]
            else:
                if nums[mid] == nums[mid - 1]:
                    if mid % 2 == 1:
                        l = mid + 1
                    else:
                        r = mid - 1
                elif nums[mid] == nums[mid + 1]:
                    if mid % 2 == 1:
                        r = mid - 1
                    else:
                        l = mid + 1

        return -1


            


