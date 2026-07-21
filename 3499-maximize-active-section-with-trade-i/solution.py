class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        
        s += "1"
        s = "1" + s

        prev_zero, nxt_zero = 0, 0
        switch = False

        total_one = 0

        ans = 0

        for i in range(1,len(s)):
            if s[i] == "1":
                if prev_zero == 0:
                    total_one += 1
                    continue

                if nxt_zero == 0:
                    switch = True
                else:
                    ans = max(ans, prev_zero + nxt_zero)    
                    prev_zero, nxt_zero = nxt_zero, 0
                total_one += 1
            else:
                if not switch:
                    prev_zero += 1
                else:
                    nxt_zero += 1
                    
        return ans + (total_one - 1)


            