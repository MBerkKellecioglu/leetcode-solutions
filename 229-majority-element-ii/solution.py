class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        cand1 = -1
        cand2 = -1
        
        c1,c2 = 0,0
        
        ans = []
        
        n = len(nums)
        
        for num in nums:
            if cand1 == num:
                c1 += 1
            elif cand2 == num:
                c2 += 1
            elif c1 == 0:
                cand1 = num
                c1 = 1
            elif c2 == 0:
                cand2 = num
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        
        if c1 > 0:
            c1 = 0
            for num in nums:
                if num == cand1:
                    c1 += 1
        
        if c2 > 0:
            c2 = 0
            for num in nums:
                if num == cand2:
                    c2 += 1
        
        if c1 > n // 3:
            ans.append(cand1)
        
        if c2 > n // 3:
            ans.append(cand2)
        
        return ans
                
        
        