class Solution:
    def countKeyChanges(self, s: str) -> int:
        
        n, ans = len(s), 0

        for i in range(n - 1):
            if s[i].lower() != s[i + 1].lower():
                ans += 1
        
        return ans
