class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        
        seen = [False] * 26

        last_occur = {}
        mono_stack = []

        for i,c in enumerate(s):
            last_occur[c] = i 
    
        for i,c in enumerate(s):
            asci = ord(c) - ord('a')
            if not seen[asci]:
                while mono_stack and c < mono_stack[-1] and last_occur[mono_stack[-1]] > i:
                    seen[ord(mono_stack[-1]) - ord('a')] = False
                    mono_stack.pop()

                mono_stack.append(c)
                seen[asci] = True

        return "".join(mono_stack)
