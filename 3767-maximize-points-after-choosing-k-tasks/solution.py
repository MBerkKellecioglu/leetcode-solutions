class Solution:
    def maxPoints(self, tech1: List[int], tech2: List[int], k: int) -> int:
        
        n = len(tech1)
        ans = 0

        min_diff = []

        for i in range(n):
            t1, t2 = tech1[i], tech2[i]

            if t1 >= t2:
                k -= 1
            else:
                heappush(min_diff, (t2 - t1))
            
            ans += max(t1,t2)
        
        while k > 0:
            diff = heappop(min_diff)
            ans -= diff
            
            k -= 1
        
        return ans
                

