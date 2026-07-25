class Solution:
    def maxProduct(self, n: int) -> int:
        
        d1, d2 = -1,-1

        s = str(n)

        for c in s:
            if int(c) > d1:
                d1, d2 = int(c), d1
            elif int(c) > d2:
                d2 = int(c)
        
        return d1*d2