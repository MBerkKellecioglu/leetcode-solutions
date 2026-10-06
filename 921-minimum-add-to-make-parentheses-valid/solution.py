class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        
        b, ans = 0, 0
        
        for c in s:
            if c == '(':
                b += 1
            else:
                if b == 0:
                    ans += 1
                else:
                    b -= 1
        
        return ans + b
                