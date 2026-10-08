class Solution:
    def removeOuterParentheses(self, s: str) -> str:

        open_bracket = 0

        ans = ""

        for idx,c in enumerate(s):
            if c == '(':
                if open_bracket == 0:
                    start_idx = idx

                open_bracket += 1
            else:
                open_bracket -= 1

                if open_bracket == 0:
                    ans += s[start_idx + 1:idx]
            
        return ans



