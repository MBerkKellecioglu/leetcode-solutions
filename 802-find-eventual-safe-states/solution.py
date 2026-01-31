class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        
        n = len(graph)

        state = [0] * n
        ans = []

        def dfs(curr):
            if state[curr] != 0:
                return state[curr] == 2
            
            state[curr] = 1

            safe = True

            for neighbor in graph[curr]:
                if state[neighbor] != 1 and safe:
                    safe = safe and dfs(neighbor)
                else:
                    return False

            state[curr] = 2 if safe else -1
            return safe

        for i in range(n):
            if (state[i] == 0 and dfs(i)) or state[i] == 2:
                ans.append(i)

        return ans