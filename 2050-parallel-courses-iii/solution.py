class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        
        q = deque()
        graph = defaultdict(list)

        wait = [0] * (n + 1)

        indegree = [0] * (n + 1)

        for ui, vi in relations:
            graph[ui].append(vi)
            indegree[vi] += 1

        for i in range(1,n + 1):
            if indegree[i] == 0:
                wait[i] = time[i - 1]
                q.append(i)
        
        while q:
            curr = q.popleft()

            for neighbor in graph[curr]:
                wait[neighbor] = max(wait[neighbor], time[neighbor - 1] + wait[curr])
                indegree[neighbor] -= 1

                if indegree[neighbor] == 0:
                    q.append(neighbor)
 
        return max(wait)


