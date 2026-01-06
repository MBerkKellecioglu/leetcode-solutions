class Solution:
    def trailingZeroes(self, n: int) -> int:
        
        ans = (n // 5)

        start = 25

        while start <= n:
            ans += (n // start)
            start *= 5
        
        return ans