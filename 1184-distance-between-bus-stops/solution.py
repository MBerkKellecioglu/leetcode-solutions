class Solution:
    def distanceBetweenBusStops(self, dist: List[int], s: int, d: int) -> int:
      
        total = sum(dist)
        
        op1  = 0
        
        s,d = min(s,d), max(s,d)
        
        for i in range(s, d):
            op1 += dist[i]
            
        return min(op1, total - op1)
            