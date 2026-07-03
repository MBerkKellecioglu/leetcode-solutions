class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        
        graph = defaultdict(list)

        weights = []

        n = len(online)

        for source,destination,weight in edges:
            if online[source] and online[destination]:
                graph[source].append((weight,destination))
                weights.append(weight)
        
        weights.sort()

        def djkstra(graph, min_cost, k, n):
            pq = []
            dists = [float("inf")] * n

            heappush(pq, (0,0)) # first cost then destination

            dists[0] = 0

            while pq:
                dist, source = heappop(pq)

                if source == n - 1:
                    return dist <= k

                if dist > dists[source]:
                    continue
                
                for weight, destination in graph[source]:
                    if weight >= min_cost and dists[source] + weight < dists[destination]:
                        dists[destination] = dists[source] + weight
                        heappush(pq, (dists[destination], destination))
            
            return dists[n - 1] <= k

        l, r, ans = 0, len(weights) - 1, -1

        while l <= r:
            mid = (l + r) // 2

            if djkstra(graph, weights[mid], k, n):
                ans = weights[mid]
                l = mid + 1
            else:
                r = mid - 1
        
        return ans