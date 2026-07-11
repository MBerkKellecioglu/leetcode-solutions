class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        
        graph = defaultdict(list)

        checked = [False] * n

        ans = 0

        for ai, bi in edges:
            graph[ai].append(bi)
            graph[bi].append(ai)
        
        def dfs(curr):
            nonlocal connected
            nonlocal edge_count
            nonlocal length 

            if len(graph[curr]) != edge_count:
                connected = False
            
            length += 1

            for neighbor in graph[curr]:
                if not checked[neighbor]:
                    checked[neighbor] = True
                    dfs(neighbor)


        for i in range(n):
            if not checked[i]:
                connected = True
                edge_count = len(graph[i])
                length = 0
                checked[i] = True

                dfs(i)

                if connected and edge_count == length - 1:
                    ans += 1
        
        return ans