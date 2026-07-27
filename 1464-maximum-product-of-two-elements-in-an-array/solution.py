class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        m1, m2 = -1,-1

        for num in nums:
            if m1 < num:
                m1, m2 = num, m1
            elif m2 < num:
                m2 = num

        return (m1 - 1) * (m2 - 1)