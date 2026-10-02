class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        
        idx, n = 0, len(s)

        ans = 1

        while idx < n - 1:
            seq = 1
            while idx < n - 1 and ord(s[idx + 1]) - ord(s[idx]) == 1:
                seq += 1
                idx += 1
            
            ans = max(ans,seq)

            idx += 1
        
        return ans