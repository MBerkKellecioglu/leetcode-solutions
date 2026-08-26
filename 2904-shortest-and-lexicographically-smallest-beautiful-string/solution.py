class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        
        l,r,n = 0,0,len(s)

        ans = "1" * (n + 1)

        one = 0

        while r < n:
            one += int(s[r] == '1')

            if one >= k:
                while l < n and (s[l] == '0' or (s[l] == '1' and one - 1 >= k)):
                    one -= int(s[l] == '1')
                    l += 1

                curr = s[l:r+1]

                if len(ans) > len(curr) or (len(ans) == len(curr) and ans > curr):
                    ans = curr

            r += 1

        return ans if len(ans) <= n else ""