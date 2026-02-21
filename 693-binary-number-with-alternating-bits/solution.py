class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        
        alternate = n & 1
        n >>= 1

        while n > 0:
            if alternate == (n & 1):
                return False

            alternate = (n & 1)
            n >>= 1

        return True
