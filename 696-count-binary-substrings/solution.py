class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        
        n, l, r = len(s), 0, 0

        prev, ans = 0, 0

        while r < n:
            if s[l] == s[r]:
                r += 1
            else:
                sz = r - l
                
                ans += min(prev, sz)

                prev = sz
                l = r

        sz = r - l

        ans += min(prev, sz)

        return ans


