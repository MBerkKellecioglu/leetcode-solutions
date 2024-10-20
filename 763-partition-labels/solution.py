class Solution:
    def partitionLabels(self, s: str) -> List[int]:

        last_seen = {}
        sol = []

        for i in range(len(s)):
            last_seen[s[i]] = i
        
        sz = 0
        p_end = 0

        for i in range(len(s)):

            c = s[i]
            sz += 1

            if last_seen[c] > p_end:
                p_end = last_seen[c]
            
            if i == p_end:
                sol.append(sz)
                sz = 0

        return sol
        