class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:

        primes = [2,3,5,7,11,13,17,19]
        ans = 0

        for num in range(left, right + 1):
            set_bit = 0

            while num != 0:
                set_bit += 1
                num = num & (num - 1)
     
            if set_bit in primes:
                ans += 1 
        
        return ans
    

