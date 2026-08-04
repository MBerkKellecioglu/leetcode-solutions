class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
   
        total_zeros = s.count('0')
        
        ans = total_zeros
        
        ones, zeros = 0,0
        
        for i in range(len(s)):
            if s[i] == '0':
                zeros += 1
            else:
                ones += 1
            
            ans = min(ans, ones + total_zeros - zeros)
            
        return ans
            