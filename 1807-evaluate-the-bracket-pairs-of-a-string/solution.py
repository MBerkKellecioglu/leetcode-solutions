class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        
        mp = {}

        for key,val in knowledge:
            mp[key] = val 

        idx, n = 0, len(s)

        ans = ""

        while idx < n:
            if s[idx] != '(':
                ans += s[idx]
            else:
                idx += 1
                bracket = ""
                while s[idx] != ')':
                    bracket += s[idx]
                    idx += 1
                
                if bracket in mp:
                    ans += mp[bracket]
                else:
                    ans += "?"
            
            idx += 1
        
        return ans

