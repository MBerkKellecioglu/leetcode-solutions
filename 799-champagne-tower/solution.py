class Solution:
    def champagneTower(self, poured: int, qr: int, qg: int) -> float:
        
        prev = [poured] 
        
        for i in range(qr):
            curr = [0] * (i + 2)

            for j in range(i + 1):
                overflow = max(0, prev[j] - 1)
                if overflow > 0:
                    curr[j] += (overflow / 2)
                    curr[j + 1] += (overflow / 2)

            prev = curr
        
        return min(1, prev[qg])