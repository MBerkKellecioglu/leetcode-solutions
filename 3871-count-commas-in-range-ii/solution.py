class Solution:
    def countCommas(self, n: int) -> int:
        
        digits = 0
        tmp = n

        ans = 0

        # 4,5,6 -> 1
        # 7,8,9 -> 2    555,555
        # 10,11,12 ->3

        while tmp:
            tmp //= 10
            digits += 1
        
        if digits < 4:
            return 0
        
        digits -= 1

        for i in range(3, digits):
            comma = ( (i + 1) // 3) if (i + 1) % 3 else ( (i + 1) // 3) - 1
            ans += (9* (10**i)) * comma
        

        comma = ( (digits + 1) // 3) if (digits + 1) % 3 else ( (digits + 1) // 3) - 1
        ans += (n - (10**(digits))) * comma + comma

        return ans 