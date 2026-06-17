class Solution:
    def processStr(self, s: str, k: int) -> str:
        
        sz, n = 0, len(s)

        for c in s:
            if c == "#":
                sz *= 2
            elif c == "*":
                sz = max(0, sz - 1)
            elif c.isalpha():
                sz += 1
        
        if k >= sz:
            return "."

        for i in range(n - 1, -1, -1):
            if s[i] == "#":
                sz //= 2
                if k >= sz:
                    k -= sz
            elif s[i] == "*":
                sz += 1
            elif s[i] == "%":
                k = sz - k - 1
            else:
                if k == sz - 1:
                    return s[i]
                sz -= 1

        return "."