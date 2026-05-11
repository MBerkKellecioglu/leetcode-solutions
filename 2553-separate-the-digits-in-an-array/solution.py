class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        
        ans = []

        def separate(num):

            digits = []

            while num > 0:
                digits.insert(0,num % 10)
                num //= 10
            
            return digits
        
        for i in range(len(nums)):
            ans.extend(separate(nums[i]))
        
        return ans