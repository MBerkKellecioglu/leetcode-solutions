class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        
        adj = defaultdict(list)

        for n1, n2, w in roads:
            adj[n1].append([w, n2])
            adj[n2].append([w, n1])

        minHeap = [(0, 0)]
        minCost = [float("inf")] * n
        pathCount = [0] * n

        pathCount[0] = 1

        while minHeap:
            cost, node = heappop(minHeap)

            for nei_cost, nei in adj[node]:
                if cost + nei_cost < minCost[nei]:
                    minCost[nei] = cost + nei_cost
                    pathCount[nei] = pathCount[node]

                    heappush(minHeap, (cost + nei_cost, nei) )

                elif cost + nei_cost == minCost[nei]:
                    pathCount[nei] = (pathCount[nei] + pathCount[node]) % (10**9 + 7)

        return pathCount[n - 1]