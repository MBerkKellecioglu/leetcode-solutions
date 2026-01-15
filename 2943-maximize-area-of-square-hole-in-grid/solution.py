class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        
        n, m = len(hBars), len(vBars)
        
        lsi1, lsi2 = 1, 1 # length of longest strictly (by 1) increasing sequence 

        hBars.sort()
        vBars.sort()

        for i in range(n):
            s = 1
            while i + 1 < n and hBars[i] + 1 == hBars[i + 1]:
                i += 1
                s += 1
            
            lsi1 = max(lsi1, s)

        for i in range(m):
            s = 1
            while i + 1 < m and vBars[i] + 1 == vBars[i + 1]:
                i += 1
                s += 1
            
            lsi2 = max(lsi2, s)

        return (min(lsi1, lsi2) + 1) * (min(lsi1, lsi2) + 1)



