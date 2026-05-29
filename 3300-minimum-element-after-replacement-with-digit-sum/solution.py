class Solution:
    def minElement(self, nums: List[int]) -> int:
        
        ans = float("inf")

        def calculate(num):

            total = 0

            while num > 0:
                total += (num % 10)
                num //= 10

            return total
        
        for i in range(len(nums)):
            ans = min(ans, calculate(nums[i]))
        
        return ans