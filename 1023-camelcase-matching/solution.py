class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        
        ans = []

        for query in queries:
            q,p = 0, 0
            qs, ps = len(query), len(pattern)

            valid = True

            while q < qs:
                if query[q].islower():
                    if p < ps and pattern[p] == query[q]:
                        p += 1
                    q += 1
                else:
                    if p >= ps or pattern[p] != query[q]:
                        valid = False
                        break
                    else:
                        q += 1
                        p += 1
            
            if p < ps: 
                valid = False
            
            ans.append(valid)

        return ans