class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        
        heap = []

        heapify(heap)

        adj = defaultdict(list)

        dist = [float("inf")] * n

        for s,d,w in edges:
            adj[s].append([w, d])
            adj[d].append([w * 2, s])
        
        heappush(heap, [0, 0])

        dist[0] = 0

        while heap:
            w, s = heappop(heap)

            if s == n - 1:
                break

            if dist[s] < w:
                continue
            
            for w, d in adj[s]:
                if dist[d] > w + dist[s]:
                    dist[d] = w + dist[s]
                    heappush(heap, [dist[d], d])

        return dist[n - 1] if dist[n - 1] != float("inf") else - 1 


