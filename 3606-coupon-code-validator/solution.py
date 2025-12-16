class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        
        e, g, p, r = [], [], [], [] 

        n = len(code)

        for i in range(n):
            if not bool(re.search(r'[^a-zA-Z0-9_]', code[i])) and isActive[i] and len(code[i]) > 0:
                c = businessLine[i]

                if c == "electronics":
                    e.append(code[i])
                elif c == "grocery":
                    g.append(code[i])
                elif c == "pharmacy":
                    p.append(code[i])
                elif c == "restaurant":
                    r.append(code[i])

        e.sort()
        g.sort()
        p.sort()
        r.sort()

        e.extend(g)
        e.extend(p)
        e.extend(r)

        return e 