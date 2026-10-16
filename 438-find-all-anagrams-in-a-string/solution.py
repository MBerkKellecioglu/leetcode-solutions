class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        
        freq = dict(Counter(p))

        m, n = len(p), len(s)

        l,r,matching = 0,0,m

        ans = []

        while r < n:
            while r - l + 1 > m:
                if s[l] in freq:
                    freq[s[l]] += 1

                    if freq[s[l]] > 0:
                        matching += 1
                
                l += 1

            if s[r] in freq:
                freq[s[r]] -= 1
                if freq[s[r]] >= 0:
                    matching -= 1
            
            if r - l + 1 == m and matching == 0:
                ans.append(l)
            
            r += 1
        
        return ans



