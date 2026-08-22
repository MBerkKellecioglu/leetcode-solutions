class Solution:
    def checkDivisibility(self, n: int) -> bool:
        
        tmp = n
        
        total,mul = 0,1
        
        while tmp > 0:
            digit = tmp % 10
            tmp //= 10
            
            total += digit
            mul *= digit
        
        return n % (total + mul) == 0
            