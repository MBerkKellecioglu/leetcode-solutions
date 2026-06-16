class Solution:
    def processStr(self, s: str) -> str:
    
        ans = ""

        for c in s:
            if c.isalpha():
                ans += c
            elif c == "#":
                ans += ans
            elif c == "*":
                ans = ans[:-1]
            else:
                ans = ans[::-1]
        
        return ans
