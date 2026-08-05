class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        
        graph = defaultdict(list)

        q = deque()

        for ai, bi in invocations:
            graph[ai].append(bi)

        checked = [False] * n
        sus = [False] * n
        ans = []

        sus[k] = True

        q.append(k)

        while q:
            curr = q.popleft()

            for nei in graph[curr]:
                if not sus[nei]:
                    sus[nei] = True
                    graph[nei].append(curr)
                    q.append(nei)

        for i in range(n):
            if not sus[i]:
                q.append(i)
                ans.append(i)

        while q:
            curr = q.popleft()

            for nei in graph[curr]:
                if not checked[nei]:
                    checked[nei] = True
                    q.append(nei)

                    if sus[nei]:
                        sus[nei] = False
                        ans.append(nei)
        
        return ans