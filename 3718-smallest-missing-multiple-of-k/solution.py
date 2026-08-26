class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        
        mul = [0] * 102

        for num in nums:
            if num % k == 0:
                mul[num // k] = 1
            
        for i in range(1,102):
            if mul[i] == 0:
                return k * i