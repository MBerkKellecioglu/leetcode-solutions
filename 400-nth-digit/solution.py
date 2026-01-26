class Solution:
    def findNthDigit(self, n: int) -> int:
        
        digits, last, expo = 0, 0, 0

        while n - digits > 0:
            n -= digits
            digits = 9 * (10**expo)
            if expo != 0:
                digits *= (expo + 1)
            expo += 1
        
        num = (10**(expo - 1))
        num += ceil(n / expo) - 1

        num = str(num)

        return int(num[(n % expo) - 1])