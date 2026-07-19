class Solution:
    def smallestSubsequence(self, s: str) -> str:
        
        unique = [False] * 26
        ans = ""

        last_occur = {}
        mono_stack = []

        for i,c in enumerate(s):
            asci = ord(c) - ord('a')
            last_occur[c] = i 
            if unique[asci] == False:
                unique[asci] = True
    
        for i,c in enumerate(s):
            asci = ord(c) - ord('a')
            if unique[asci]:
                while mono_stack and c < mono_stack[-1] and last_occur[mono_stack[-1]] > i:
                    unique[ord(mono_stack[-1]) - ord('a')] = True
                    mono_stack.pop()

                mono_stack.append(c)
                unique[asci] = False

        return "".join(mono_stack)
