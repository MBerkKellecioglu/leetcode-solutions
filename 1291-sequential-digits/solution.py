class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        
        ans = []
        nums = []

        for digit in range(2, 10):
            for i in range(1, 9 - (digit - 2)):
                num = str(i)
                for j in range(i + 1,i + digit):
                    num += str(j)
                
                nums.append(int(num))
        
        for i in range(len(nums)):
            if nums[i] >= low and nums[i] <= high:
                ans.append(nums[i])
        
        return ans

        
