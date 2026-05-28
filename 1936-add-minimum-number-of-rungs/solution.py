class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        
        prev, ans = 0, 0 

        ind = 0

        while ind < len(rungs):
            if prev + dist >= rungs[ind]:
                prev = rungs[ind]
            else:
                ans += ( (rungs[ind] - prev) // dist)
                if (rungs[ind] - prev) % dist == 0:
                    ans -= 1

                prev = rungs[ind]

            ind += 1

        return ans