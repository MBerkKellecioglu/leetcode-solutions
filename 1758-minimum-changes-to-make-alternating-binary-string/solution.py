class Solution:
    def minOperations(self, s: str) -> int:
        
        n = len(s)

        one, zero, switch = 0, 0, 1

        for i in range(n):
            if switch == int(s[i]):
                zero += 1
            else:
                one += 1
            
            switch ^= 1

        return min(one, zero)

