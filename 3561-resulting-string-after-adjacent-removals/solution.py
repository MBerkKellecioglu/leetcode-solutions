class Solution:
    def resultingString(self, s: str) -> str:

        stack = []

        for c in s:
            if stack and (ord(c) + 1 - ord(stack[-1])) % 26 in [0,2]:
                stack.pop()
            else:
                stack.append(c)

        return "".join(stack)
                