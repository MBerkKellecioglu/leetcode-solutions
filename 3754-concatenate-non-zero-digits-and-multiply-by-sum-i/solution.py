class Solution:
    def sumAndMultiply(self, n: int) -> int:

        if n == 0:
            return 0

        n = str(n)
        
        x = ""
        digit_sum = 0

        for c in n:
            if c != "0":
                x += c
                digit_sum += (ord(c) - ord('0'))
        
        return int(x) * digit_sum