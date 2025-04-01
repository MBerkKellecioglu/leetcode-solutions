class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        
        dup = colors * 2

        l = 0
        r = 1
        ans = 0

        while l < len(colors): 
            if ((r - l) % 2 == 1) and (dup[r] ^ dup[l]) == 0:
                l = r
                
            if ((r - l) % 2 == 0) and (dup[r] ^ dup[l]) == 1:
                l = r
                
            if (r - l + 1) == k:
                ans += 1
                l += 1

            r += 1

        return ans