class Solution:
    def minimumCost(self, source: str, target: str, org: List[str], changed: List[str], cost: List[int]) -> int:

        n, m, ans =  len(cost), len(target), 0

        adj = defaultdict(list)
        paths = defaultdict(lambda:float("inf"))

        for i in range(n):
            adj[org[i]].append([cost[i], changed[i]])

        def djkstra(adj,s,d):
            nonlocal paths
            heap = []
            dist = defaultdict(lambda:float("inf"))

            heappush(heap, [0,s])
            dist[s] = 0

            while heap:
                cost, curr = heappop(heap)

                if cost > dist[curr]:
                    continue
                
                for weight, neighbor in adj[curr]:
                    if weight + dist[curr] < dist[neighbor]:
                        dist[neighbor] = weight + dist[curr]
                        paths[(s, neighbor)] = min(paths[(s, neighbor)], dist[neighbor])
                        heappush(heap,[dist[neighbor], neighbor])
            
            paths[(s, d)] = min(paths[(s,d)], dist[d])
            return dist[d]

        for i in range(n):
                if paths[(org[i], changed[i])] == float("inf"):
                    djkstra(adj, org[i], changed[i])


        for i in range(m):
            if source[i] != target[i]:
                if paths[(source[i], target[i])] != float("inf"):
                    ans += paths[(source[i], target[i])]
                else:
                    return -1


        return ans if ans != 0 else -1