class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        
        n, ans, skip = len(nums), 1, len(nums) - 1

        while skip > - 1 and nums[skip - 1] == nums[skip]:
            skip -= 1

        skip -= 1

        if skip >= 0:
            last = nums[skip]
            alter = nums[skip] > nums[skip + 1]
            ans += 1

        # alter is for checking whether we are looking for negative diff or positive diff
        # if alter is true we are looking for positive diff else we are looking for negative diff

        for i in range(skip, -1, -1):  
            if(last > nums[i] and alter) or (last < nums[i] and (not alter)):
                alter ^= 1
                ans += 1
            
            last = nums[i]
        
        return ans
