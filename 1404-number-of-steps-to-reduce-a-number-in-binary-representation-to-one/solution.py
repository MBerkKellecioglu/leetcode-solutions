class Solution:
    def numSteps(self, s: str) -> int:
        
        step, num, exp = 0, 0, 0

        for i in range(len(s) - 1, -1, -1):
            num += int(s[i]) * (1 << exp)
            exp += 1
        
        while num != 1:
            if num & 1:
                num += 1
            else:
                num //= 2
            
            step += 1
        
        return step
