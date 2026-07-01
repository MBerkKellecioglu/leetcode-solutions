class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        
        la, lb, lc = -1,-1,-1 # last seen positions

        start, ans = 0, 0

        for i in range(len(s)):
            c = s[i]

            if c == "a":
                la = i
            elif c == "b":
                lb = i
            else:
                lc = i
            
            if la != -1 and lb != -1 and lc != -1:
                start = i
                break

        for i in range(start, len(s)):
            c = s[i]

            if c == "a":
                la = i
                ans += min(lb, lc) + 1
            elif c == "b":
                lb = i
                ans += min(la, lc) + 1
            else:
                lc = i
                ans += min(lb, la) + 1
        
        return ans