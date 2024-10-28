class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        d = abs(dividend)
        dv = abs(divisor)

        ans = 0

        while d >= dv:
            expo = dv
            mul = 1

            while d >= expo:
                d -= expo
                ans += mul
                expo += expo
                mul += mul
        
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            ans *= -1

        if ans > 2147483647:
            return 2147483647
        
        if ans < -2147483648:
            return - 2147483648
            
        return ans
