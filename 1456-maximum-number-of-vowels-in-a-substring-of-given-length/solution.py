class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        
        n = len(s)
        l = 0
        r = 0

        vowels = "aeiou"

        ans = 0
        count = 0

        for r in range(k): # Creating our Window
            if s[r] in vowels:
                count += 1
        
        ans = max(ans, count)

        r += 1

        while r < n: # Sliding our Window
            if s[l] in vowels:
                count -= 1
            
            if s[r] in vowels:
                count += 1
            
            r += 1
            l += 1
            
            ans = max(ans, count)
        
        return ans





