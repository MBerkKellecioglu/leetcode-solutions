class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        
        levels = {}

        b, n = 0, len(s)

        ans = 0

        for i in range(n):
            if s[i] == '(':
                b += 1
            else:
                b -= 1

                if s[i - 1] == '(':
                    if b in levels:
                        levels[b] += 1
                    else:
                        levels[b] = 1
        
        for level, freq in levels.items():
            ans += freq * (1 << level)
        
        return ans