class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        dist = [float("inf")] * (n + 1) 

        heap = []

        adj = defaultdict(list)

        # source, destination, weight
        for s, d, w in times:
            adj[s].append([w,d])

        heappush(heap, [0, k])
        dist[k] = 0
        
        while heap:
            w, s = heappop(heap)

            if w > dist[s]:
                continue

            for w, d in adj[s]:
                if dist[s] + w < dist[d]:
                    dist[d] = dist[s] + w
                    heappush(heap, [dist[d], d])

        dist = dist[1:]

        ans = max(dist)

        return ans if ans != float("inf") else -1