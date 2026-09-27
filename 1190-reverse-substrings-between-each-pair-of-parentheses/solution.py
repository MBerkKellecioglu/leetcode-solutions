class Solution:
    def reverseParentheses(self, s: str) -> str:
        
        # some fckn wormhole tech i suprisingly DONT KNOW A SHIT ABOUT
        # you learn something every FUCKING day
        # there is no way im mastering this shit

        pairs = {}

        stack = []

        for i,c in enumerate(s):
            if c == '(':
                stack.append(i)
            elif c == ')':
                j = stack.pop()
                pairs[i] = j
                pairs[j] = i
        
        ans = ""
        direction, idx = 1, 0

        while idx < len(s):
            if s[idx] == '(' or s[idx] == ')':
                idx = pairs[idx]
                direction *= -1
            else:
                ans += s[idx]
            
            idx += direction
        
        return ans


        