class Solution:
    def bulbSwitch(self, n: int) -> int:

        if n == 1: 
            return 1
        
        limit = ceil(sqrt(n))

        ans = 0

        for i in range(1,limit + 1):
            if i * i <= n:
                ans += 1

        return ans