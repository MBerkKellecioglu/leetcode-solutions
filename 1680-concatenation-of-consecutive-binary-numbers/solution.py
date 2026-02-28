class Solution:
    def concatenatedBinary(self, n: int) -> int:

        if n == 1:
            return n
        
        ans, digits = 6, 2 

        MOD = (10**9) + 7

        for num in range(3, n + 1):
            ans <<= num.bit_length()
            ans |= num
            ans %= MOD

        return ans
