class Solution:
    def binaryGap(self, n: int) -> int:
        
        prev, ans, curr = -1, 0, 0

        while n > 0:
            if (n & 1):
                if prev != -1:
                    ans = max(ans, curr - prev)
                
                prev = curr
                    
            n >>= 1
            curr += 1

        return ans