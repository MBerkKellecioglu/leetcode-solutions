class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        
        n = len(s)
        
        prev = [0] * n
        
        prev[0] = 1
        
        for i in range(1,n):
            nxt = [0] * n
            nxt[i] = 1
            for j in range(i - 1, -1,-1):
                if s[i] == s[j]:
                    nxt[j] = prev[j + 1] + 2
            
                nxt[j] = max(nxt[j], prev[j], nxt[j + 1])
            
            prev = nxt

        
        return prev[0]
                