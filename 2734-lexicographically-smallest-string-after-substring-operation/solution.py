class Solution:
    def smallestString(self, s: str) -> str:
        
        start, n = 0, len(s)

        ans = ""

        while start < n and s[start] == "a":
            start += 1
            ans += "a"

        if start >= n:
            ans = ans[:-1]
            ans += "z"
            return ans

        end = s.find("a", start)

        if end == -1:
            end = n 

        for i in range(start, end):
            ans += chr(ord(s[i]) - 1)

        ans += s[end:]

        return ans


