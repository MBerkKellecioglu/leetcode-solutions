class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        
        alpha = dict(Counter(s))

        ans = ""

        for c in y:
            if c in alpha:
                ans += c * alpha[c]
                alpha[c] = 0
        
        for c,freq in alpha.items():
            if freq != 0:
                ans += c * freq

        return ans