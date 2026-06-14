class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        
        tree = defaultdict(list)

        depth = -1

        MOD = 10**9 + 7

        for n1, n2 in edges:
            tree[n1].append(n2)
            tree[n2].append(n1)

        def dfs(curr, parent, d):
            nonlocal depth

            depth = max(d, depth)

            for nxt in tree[curr]:
                if nxt != parent:
                    dfs(nxt, curr, d + 1)
        
        dfs(1, -1, 0)
            
        return (2**(depth - 1)) % MOD
