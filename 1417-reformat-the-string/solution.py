class Solution:
    def reformat(self, s: str) -> str:

        letters = []
        digits = []

        ans = ""

        for c in s:
            if c.isalpha():
                letters.append(c)
            else:
                digits.append(c)
        
        if abs(len(letters) - len(digits)) >= 2:
            return ""
        
        cycle = len(letters) >= len(digits) # 0 for digits 1 for letters
        
        while 1:
            if cycle:
                if len(letters) > 0:
                    ans += letters[-1]
                    letters.pop()
                else:
                    break
            else:
                if len(digits) > 0:
                    ans += digits[-1]
                    digits.pop()
                else:
                    break
            
            cycle ^= 1

        return ans
