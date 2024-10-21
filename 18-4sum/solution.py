class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        nums.sort()

        sol = []

        for i in range(len(nums) - 3):
            if i != 0 and nums[i] == nums[i - 1]: continue

            anchor1 = nums[i]

            for j in range(i + 1, len(nums) - 2):
                if j != i + 1 and nums[j] == nums[j - 1]: continue
                
                anchor2 = nums[j]
                l = j + 1
                r = len(nums) - 1

                while l < r:
                    sum = anchor1 + anchor2 + nums[l] + nums[r]

                    if sum < target: 
                        l += 1
                    elif sum > target:
                         r -= 1
                    else:
                        sol.append([anchor1, anchor2, nums[l], nums[r]])
                        l += 1
                        r -= 1

                        while l < r and nums[l] == nums[l - 1]: l += 1
                        while l < r and nums[r] == nums[r + 1]: r -= 1
        
        return sol