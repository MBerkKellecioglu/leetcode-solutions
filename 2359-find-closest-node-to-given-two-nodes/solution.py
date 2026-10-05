class Solution:
    def closestMeetingNode(self, edges: list[int], node1: int, node2: int) -> int:
        
        n = len(edges)

        dist = [[float("inf"), float("inf")] for _ in range(n)] 

        dist[node1][0] = 0
        dist[node2][1] = 0

        q = deque()

        q.append((node1,0))
        q.append((node2,1))

        d = 1

        while q:
            sz = len(q)

            while sz > 0:
                curr, start = q.popleft()

                nxt = edges[curr]

                if edges[curr] != -1 and dist[nxt][start] == float("inf"):
                    dist[nxt][start] = d

                    q.append((nxt,start))

                sz -= 1
            
            d += 1
        
        maxi = float("inf")
        ans = -1

        for idx,d in enumerate(dist):
            if max(d) < maxi:
                maxi = max(d)
                ans = idx
        
        return ans


