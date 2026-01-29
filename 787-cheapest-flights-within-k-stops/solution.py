class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        dist = [float("inf")] * n

        dist[src] = 0

        for i in range(k + 1):
            temp = dist[:]

            for s,d,w in flights:
                if dist[s] + w < temp[d]:
                    temp[d] = dist[s] + w
            
            dist = temp[:]
        
        return dist[dst] if dist[dst] != float("inf") else -1
