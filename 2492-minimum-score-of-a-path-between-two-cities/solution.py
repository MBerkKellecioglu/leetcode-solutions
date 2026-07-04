class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        
        # simple BFS would do the trick but since graph is undirected checked array is needed
        q = deque([1])
        checked = [False] * (n + 1)
        ans = float("inf")

        graph = defaultdict(list)

        for a,b,dist in roads:
            graph[a].append((dist,b))
            graph[b].append((dist,a))

        while q:
            curr = q.popleft()

            if checked[curr]:
                continue
            
            checked[curr] = True

            for dist, neigh in graph[curr]:
                if not checked[neigh]:
                    q.append(neigh)
                    ans = min(ans, dist)

        
        return ans